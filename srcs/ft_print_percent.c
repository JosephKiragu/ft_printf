/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:43:03 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/20 18:43:06 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libftprintf.h"

void	ft_print_percent(t_placeholder *holder)
{
	holder->argument = ft_append_char("", holder->conversion);
	if (!holder->justify_left)
	{	
		ft_pad_left(&holder->argument, holder->padding, holder->width);
	}
	else
		ft_pad_right(&holder->argument, ' ', holder->width);
	holder->counter = ft_strlen(holder->argument);
}
