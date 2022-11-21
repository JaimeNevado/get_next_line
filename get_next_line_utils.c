/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:48 by jaimenevado       #+#    #+#             */
/*   Updated: 2022/11/21 14:12:35 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//STRJOIN cambiada con ayuda de asalas-
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	int		strjoin_len;

	if ((!s1) && (!s2))
		return (NULL);
	if (!s1)
		strjoin_len = ft_strlen(s2);
	if (!s2)
		strjoin_len = ft_strlen(s1);
	if (s1 && s2)
		strjoin_len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)malloc ((strjoin_len + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	if (!s1)
		ft_strlcpy(strjoin, s2, strjoin_len + 1);
	if (!s2)
		ft_strlcpy(strjoin, s1, strjoin_len + 1);
	if (s1 && s2)
	{
		ft_strlcpy(strjoin, s1, strjoin_len + 1);
		ft_strlcat(strjoin, s2, strjoin_len + 1);
	}
	return (strjoin);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	l;

	l = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_l;
	unsigned int	src_l;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	j = 0;
	if ((dstsize == 0) || (dstsize <= dst_l))
		return (src_l + dstsize);
	while (dst[i] != '\0')
		i++;
	while ((src[j] != '\0') && (j < dstsize - dst_l - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_l + src_l);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
