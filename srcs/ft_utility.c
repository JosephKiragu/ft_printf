/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:44:58 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/20 18:45:01 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libftprintf.h"

char	*ft_append_char(char const *s1, char const c)
{
	char	*concat;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	concat = (char *) malloc (sizeof(char) * (len + 2));
	if (!concat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	concat[i++] = c;
	concat[i] = '\0';
	return (concat);
}

char	*ft_strndup(const char *str, size_t n)
{
	int		size;
	char	*dest;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if ((size_t) size > n)
		size = n;
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, size);
	dest[size] = '\0';
	return (dest);
}

void	strrev(char *str)
{
	size_t	len;
	size_t	i;
	size_t	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}
