/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josephkiragu <josephkiragu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:44:40 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/21 16:02:21 by josephkirag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_struct_printf(const char *format, va_list vargs)
{
	t_fmt	*fmt;
	int		len;

	fmt = ft_init_format(format, vargs);
	if (!fmt)
		return (0);
	while (fmt->format[fmt->i])
	{
		if (fmt->format[fmt->i] == '%')
		{
			if (fmt->format[fmt->i + 1])
				ft_placeholders(fmt);
			else
				break ;
		}
		else
			fmt->count += write(1, &fmt->format[fmt->i++], 1);
	}
	len = fmt->count;
	free(fmt);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	vargs;
	int		len;

	if (!format)
		return (0);
	va_start(vargs, format);
	len = ft_struct_printf(format, vargs);
	va_end(vargs);
	return (len);
}
