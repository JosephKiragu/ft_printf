/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:21:29 by jkiragu           #+#    #+#             */
/*   Updated: 2022/04/29 23:39:35 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s1, int c, size_t len)
{
	unsigned char	*sptr;

	sptr = (unsigned char *)s1;
	while (len--)
	{
		*sptr++ = c;
	}
	return (s1);
}
