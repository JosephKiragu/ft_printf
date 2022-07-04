/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:13:35 by jkiragu           #+#    #+#             */
/*   Updated: 2022/03/18 16:13:44 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1ptr;
	unsigned const char	*s2ptr;
	size_t				j;

	j = 0;
	s1ptr = (unsigned const char *)s1;
	s2ptr = (unsigned const char *)s2;
	while (j < n)
	{
		if (s1ptr[j] != s2ptr[j])
		{
			return (s1ptr[j] - s2ptr[j]);
		}
		++j;
	}
	return (0);
}
