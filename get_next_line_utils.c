/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:40:59 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/14 23:58:56 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(char *s, int c)
{
	if (!s)
		    return (0);
	while (*s != (char)c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}
char	*ft_strdup( char *s)
{
	char	*n;

	n = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s, ft_strlen(s) + 1);
	return (n);
}

size_t	ft_strlcpy(char *dst,  char *src, size_t size)
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
void	*ft_memcpy(void *dest,  void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	while (n--)
		*dest_cast++ = *src_cast++;
	return (dest);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*n;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	n = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !n)
		return (NULL);
	ft_memcpy(n, s1, ft_strlen(s1));
	ft_strlcpy(n + ft_strlen(s1), s2, ft_strlen(s2) + 1);
    free(s1);
	return (n);
}
