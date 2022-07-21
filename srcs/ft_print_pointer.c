/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josephkiragu <josephkiragu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:43:20 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/21 16:01:53 by josephkirag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*ft_set_null(t_placeholder *holder)
{
	char	*number;

	if (holder->precision > -1)
	{
		number = (char *) malloc (sizeof(char) * (holder->precision + 1));
		ft_memset(number, '0', (size_t)holder->precision);
		number[holder->precision] = '\0';
	}
	else
		number = ft_strdup("0");
	return (number);
}

void	ft_print_pointer(t_fmt *fmt, t_placeholder *holder)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->vargs, void *);
	if (!ptr)
		number = ft_set_null(holder);
	else
		number = hex_itoa((__UINTPTR_TYPE__)ptr, HEX_LOWER_BASE);
	holder->argument = ft_strjoin(LC_HEX_PREFIX, number);
	free(number);
	if (!holder->justify_left)
		ft_pad_left(&holder->argument, holder->padding, holder->width);
	else
		ft_pad_right(&holder->argument, ' ', holder->width);
	holder->counter = ft_strlen(holder->argument);
}
