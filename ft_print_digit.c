# include "libftprintf.h"

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
	int sign;
	long int num;
	char *digit;

	sign = 1;
	num = (int) va_arg(fmt->vargs, int);

	if (num < 0)
		sign *= -1;

	digit = ft_itoa(num);
	holder->argument = ft_strdup(digit);
	free(digit);
	if (holder->precision > -1)
	{
		if (!holder->precision && num == 0) // if holder precision == 1
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
