/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:16 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/20 18:40:20 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libftprintf.h"

t_fmt	*ft_init_format(const char *format, va_list vargs)
{
	t_fmt	*fmt;

	fmt = malloc (sizeof(t_fmt));
	if (!fmt)
		return (0);
	fmt->format = format;
	va_copy(fmt->vargs, vargs);
	fmt->i = 0;
	fmt->count = 0;
	return (fmt);
}

t_placeholder	*ft_init_placeholder(void)
{
	t_placeholder	*holder;

	holder = malloc (sizeof(t_placeholder));
	if (!holder)
		return (0);
	holder->argument = NULL;
	holder->conversion = '\0';
	holder->prefix = ft_strdup("");
	holder->padding = ' ';
	holder->justify_left = 0;
	holder->width = 0;
	holder->precision = -1;
	holder->counter = 0;
	return (holder);
}

void	ft_placeholders(t_fmt *fmt)
{
	t_placeholder	*holder;

	fmt->i++;
	holder = ft_init_placeholder();
	ft_parser(fmt, holder);
	// if (holder->conversion == '\0')
	// {
	// 	//holder->conversion = NULL;
	// 	printf("inside holder conversion tester\n");
	// }
	// //printf("Holder<-conversion inside ft_placeholders = %c\n", holder->conversion);
	if (holder->conversion != '\0')
	{
		ft_convert_by_type(fmt, holder);
		
		fmt->count += write(1, holder->argument, holder->counter);
		// printf("Value of holder<-argument in ft_init = %s\n",holder->argument);
		// printf("Value of fmt-> count = %zu\n", fmt->count);
		free(holder->argument);
	}
	
	free(holder->prefix);
	free(holder);
}
