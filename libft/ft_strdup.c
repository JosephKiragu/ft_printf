/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:23:30 by jkiragu           #+#    #+#             */
/*   Updated: 2022/05/11 17:08:30 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1ptr;
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_strlen(s1) + 1;
	if (!s1)
		return (NULL);
	s1ptr = malloc(sizeof(char) * len);
	if (!s1ptr)
		return (NULL);
	while (s1[j])
	{
		s1ptr[j] = s1[j];
		++j;
	}
	s1ptr[j] = '\0';
	return (s1ptr);
}
