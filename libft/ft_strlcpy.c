/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:28:59 by jkiragu           #+#    #+#             */
/*   Updated: 2022/03/18 16:29:06 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t cpy_len)
{
	size_t	srclen;

	srclen = 0;
	while (*(src + srclen))
	{
		srclen++;
	}
	if (srclen + 1 < cpy_len)
		ft_memcpy(dst, src, srclen + 1);
	else if (cpy_len != 0)
	{
		ft_memcpy(dst, src, cpy_len - 1);
		dst[cpy_len - 1] = '\0';
	}
	return (srclen);
}
