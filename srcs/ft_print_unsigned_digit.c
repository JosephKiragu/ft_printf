/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:44:04 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/20 18:44:09 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libftprintf.h"

char	*pos_itoa(unsigned int num)
{
	char			*str;
	unsigned int	len;

	len = 0;
	str = ft_calloc(11, sizeof(char));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[len++] = '0' +(num % 10);
		num = num / 10;
	}
	strrev(str);
	return (str);
}

void	ft_print_unsigned_digit(t_fmt *fmt, t_placeholder *holder)
{
	unsigned int	number;
	char			*digit;

	number = (unsigned int) va_arg(fmt->vargs, unsigned int);
	digit = pos_itoa(number);
	holder->argument = ft_strdup(digit);
	free(digit);
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
	if (!holder->justify_left)
		ft_pad_left(&holder->argument, holder->padding, holder->width);
	else
		ft_pad_right(&holder->argument, ' ', holder->width);
	holder->counter = ft_strlen(holder->argument);
}
