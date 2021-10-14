/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:40:59 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/13 18:00:02 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (*str++ == '\0')
			return (NULL);
	return ((char *)str);
}
char	*ft_strdup(const char *s)
{
	char	*n;

	n = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s, ft_strlen(s) + 1);
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (src == NULL)
		return (0);
	if (size > 0)
	{
		while (*src && (size--) - 1)
			*dst++ = *src++;
		*(dst) = '\0';
	}
	return (len_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	n = malloc((len + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	ft_strlcpy(n, s + start, len + 1);
	return (n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	while (n--)
		*dest_cast++ = *src_cast++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;

	if (!s1 || !s2)
		return (NULL);
	n = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s1, ft_strlen(s1));
	ft_strlcpy(n + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (n);
}
