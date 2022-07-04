/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:14:20 by jkiragu           #+#    #+#             */
/*   Updated: 2022/04/30 00:04:50 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstptr;
	char	*srcptr;

	dstptr = (char *)dst;
	srcptr = (char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dstptr > srcptr)
	{
		while (len--)
		{
			*(dstptr + len) = *(srcptr + len);
		}
		return (dst);
	}
	else
	{
		while (len--)
		{
			*dstptr++ = *srcptr++;
		}
		return (dst);
	}
	if (!dst || !src)
		return (NULL);
}
