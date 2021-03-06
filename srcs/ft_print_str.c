/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josephkiragu <josephkiragu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:43:38 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/21 16:02:02 by josephkirag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_str(t_fmt *fmt, t_placeholder *holder)
{
	char	*str;
	char	*temp;
	int		size;

	str = ft_strdup(va_arg(fmt->vargs, char *));
	if (!str)
		str = ft_strdup("(null)");
	size = ft_strlen(str);
	holder->argument = (char *) malloc(sizeof(char) * (size + 1));
	if (!holder->argument)
		return ;
	ft_strlcpy(holder->argument, str, size + 1);
	if (holder->precision > -1)
	{
		temp = holder->argument;
		holder->argument = ft_strndup(temp, (size_t) holder->precision);
		free(temp);
	}
	if (!holder->justify_left)
		ft_pad_left(&holder->argument, ' ', holder->width);
	else
		ft_pad_right(&holder->argument, ' ', holder->width);
	holder->counter = ft_strlen(holder->argument);
	free (str);
}
