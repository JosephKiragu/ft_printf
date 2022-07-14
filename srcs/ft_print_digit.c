# include "../includes/libftprintf.h"


static void	ft_convbase(unsigned long long nbr, char *num, char *base, size_t i)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (nbr >= (unsigned long long)len_base)
		ft_convbase((nbr / len_base), num, base, (i - 1));
	num[i] = base[nbr % len_base];
}

static size_t	ft_countsize(unsigned long long n, size_t len_base)
{
	if ((n / len_base) == 0)
		return (1);
	else
		return (1 + ft_countsize(n / len_base, len_base));
}

char	*ft_uitoa_base(unsigned long long nbr, char *base)
{
	size_t		len_nbr;
	size_t		len_base;
	char		*number;

	len_base = ft_strlen(base);
	len_nbr = ft_countsize(nbr, len_base);
	number = malloc((len_nbr + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len_nbr--] = '\0';
	ft_convbase(nbr, number, base, len_nbr);
	return (number);
}

void ft_digit_width(t_placeholder *holder, int sign)
{
	if (holder->justify_left)
	{
		ft_add_prefix(holder, sign);
		ft_pad_right(&holder->argument, ' ', holder->width);
	}
	else
	{
		if (holder->padding == ' ')
		{
			ft_add_prefix(holder, sign);
			ft_pad_left(&holder->argument, holder->padding, holder->width);
		}
		else if (holder->padding =='0')
		{
			if (sign < 0 || ft_strchr(holder->prefix, ' ') || ft_strchr(holder->prefix, '+'))
				ft_pad_left(&holder->argument, holder->padding, holder->width - 1);
			else 
				ft_pad_left(&holder->argument, holder->padding, holder->width);
			ft_add_prefix(holder, sign);
		}
	}
}
	

void ft_print_digit(t_fmt *fmt, t_placeholder *holder)
{
	int			sign;
	long int	arg;

	sign = 1;
	arg = (int) va_arg(fmt->vargs, int);
	if (arg < 0)
		sign *= -1;
	holder->argument = ft_uitoa_base(sign * arg, "0123456789");
	if (holder->precision > -1)
	{
		if (!holder->precision && arg == 0)
		{
			free(holder->argument);
			holder->argument = ft_strdup("");
		}
		ft_pad_left(&holder->argument, '0', holder->precision);
		holder->padding = ' ';
	}
	ft_digit_width(holder, sign);
	holder->counter = ft_strlen(holder->argument);
}






// {
// 	int sign;
// 	long int num;
// 	char *digit;

// 	sign = 1;
// 	num = (int) va_arg(fmt->vargs, int);

// 	if (num < 0)
// 		sign *= -1;

// 	digit = ft_itoa(num);
// 	holder->argument = ft_strdup(digit);
// 	free(digit);
// 	if (holder->precision > -1)
// 	{
// 		if (!holder->precision && num == 0) // if holder precision == 1
// 		{
// 			free(holder->argument);
// 			holder->argument = ft_strdup("");
// 		}
// 		ft_pad_left(&holder->argument, '0', holder->precision);
// 		holder->padding = ' ';
// 	}
// 	ft_digit_width(holder, sign);
// 	holder->counter = ft_strlen(holder->argument);

// }
