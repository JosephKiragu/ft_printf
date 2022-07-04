/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:22:34 by jkiragu           #+#    #+#             */
/*   Updated: 2022/05/11 17:07:39 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == c)
		{
			return ((char *)str + j);
		}
		j++;
	}
	if (str[j] == c)
	{
		return ((char *)str + j);
	}
	return (NULL);
}
