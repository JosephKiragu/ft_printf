/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josephkiragu <josephkiragu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:38:32 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/21 16:03:58 by josephkirag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_convert_by_type(t_fmt *fmt, t_placeholder *holder)
{
	if (holder->conversion == 'c' )
		ft_print_char(fmt, holder);
	else if (holder->conversion == 's')
		ft_print_str(fmt, holder);
	else if (holder->conversion == 'i' || holder->conversion == 'd')
		ft_print_digit(fmt, holder);
	else if (holder->conversion == 'u')
		ft_print_unsigned_digit(fmt, holder);
	else if (holder->conversion == 'x')
		ft_print_hex(fmt, holder, HEX_LOWER_BASE);
	else if (holder->conversion == 'X')
		ft_print_hex(fmt, holder, HEX_UPPER_BASE);
	else if (holder->conversion == 'p')
		ft_print_pointer(fmt, holder);
	else
		ft_print_percent(holder);
}

void	ft_pad_left(char **str, char padding, int width)
{
	char	*temp;
	size_t	strlen;
	size_t	padlen;

	strlen = ft_strlen(*str);
	if (!width || width < (int)strlen)
		width = strlen;
	temp = (char *) malloc(sizeof(char) * width);
	if (!temp)
		return ;
	padlen = width - strlen;
	ft_memset(temp, padding, padlen);
	temp[padlen] = '\0';
	ft_strlcat(temp, *str, width + 1);
	free(*str);
	*str = temp;
}

void	ft_pad_right(char **str, char padding, int width)
{
	char	*temp;
	size_t	strlen;
	size_t	padlen;

	strlen = ft_strlen(*str);
	if (!width || width < (int)strlen)
		width = strlen;
	temp = (char *) malloc(sizeof(char) * width);
	if (!temp)
		return ;
	ft_strlcpy(temp, *str, width + 1);
	padlen = width - strlen;
	ft_memset(&temp[strlen], padding, padlen);
	temp[width] = '\0';
	free(*str);
	*str = temp;
}

void	ft_hex_prefix(t_placeholder *holder)
{
	char	*temp;

	temp = holder->argument;
	if (ft_strchr(holder->prefix, '#'))
	{
		if (holder->conversion == 'x')
			holder->argument = ft_strjoin(LC_HEX_PREFIX, temp);
		if (holder->conversion == 'X')
			holder->argument = ft_strjoin(UC_HEX_PREFIX, temp);
		free(temp);
	}
}

void	ft_add_prefix(t_placeholder *holder, int sign)
{
	int	len;

	len = (int)ft_strlen(holder->argument);
	if (holder->conversion == 'd' || holder->conversion == 'i')
	{
		len += 1;
		if (ft_strchr(holder->prefix, PLUS) && sign == 1)
			ft_pad_left(&holder->argument, PLUS, len);
		else if (ft_strchr(holder->prefix, SPACE) && sign == 1)
			ft_pad_left(&holder->argument, SPACE, len);
		else if (sign == -1)
			ft_pad_left(&holder->argument, MINUS, len);
	}
	else if (holder->conversion == 'x' || holder->conversion == 'X')
		ft_hex_prefix(holder);
}
