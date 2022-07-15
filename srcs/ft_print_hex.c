# include "../includes/libftprintf.h"

char	*hex_itoa(unsigned long long num, char *base)
{
	char			*str;
	unsigned int	len;
	size_t			base_len;

	len = 0;
	base_len = ft_strlen(base);
	str = ft_calloc(base_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[len++] = base[num % base_len];
		num /= base_len;
	}
	strrev(str);
	return (str);
}

void	ft_print_hex(t_fmt *fmt, t_placeholder *holder, char *base)
{
	unsigned int	number;
	char			*hex;

	number = (unsigned int) va_arg(fmt->vargs, unsigned int);
	hex = hex_itoa((unsigned long)number, base);
	holder->argument = ft_strdup(hex);
	free(hex);
	if (holder->precision > -1)
	{
		if (!holder->precision && number == 0)
		{
			free(holder->argument);
			holder->argument = ft_strdup("");
		}
		ft_pad_left(&holder->argument, '0', holder->precision);
		holder->padding = ' ';
	}
	if (number)
		ft_hex_prefix(holder);
	if (!holder->justify_left)
		ft_pad_left(&holder->argument, holder->padding, holder->width);
	else
		ft_pad_right(&holder->argument, ' ', holder->width);
	holder->counter = ft_strlen(holder->argument);
}
