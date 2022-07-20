/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:55 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/20 18:40:59 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libftprintf.h"

void	ft_print_char(t_fmt *fmt, t_placeholder *holder)
{
	char	value;

	value = va_arg(fmt->vargs, int);
	if (!holder->width)
			holder->width += 1;
	holder->argument = (char *)malloc(sizeof(char) * holder->width);
	if (!holder->argument)
		return ;
	ft_memset(holder->argument, SPACE, holder->width);
	if (holder->justify_left == 1)
		holder->argument[0] = value;
	else
		holder->argument[holder->width - 1] = value;
	holder->counter = holder->width;
}
