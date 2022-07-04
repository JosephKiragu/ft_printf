/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:45:38 by jkiragu           #+#    #+#             */
/*   Updated: 2022/05/11 17:16:35 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	x;
	size_t	j;

	x = 0;
	j = 0;
	dest = (char *)malloc((len + 1) * sizeof(*s));
	if (!dest)
		return (NULL);
	while (s[x])
	{
		if (x >= start && j < len)
		{
			dest[j] = s[x];
			j++;
		}
		x++;
	}
	dest[j] = 0;
	return (dest);
}
