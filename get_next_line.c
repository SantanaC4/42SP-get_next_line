/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:46:26 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/15 22:23:46 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *x)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!x[i])
		return (NULL);
	while (x[i] && x[i++] != '\n')
		;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = x[i];
	return (line);
}

char	*get_newline_chr(int fd, char *backup)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(backup, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*new_backup(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	while (backup[i] && backup[i++] != '\n')
		;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = ft_strdup(ft_strchr(backup, '\n') + 1);
	free(backup);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = get_newline_chr(fd, backup);
	if (!backup)
		return (NULL);
	result = get_line(backup);
	backup = new_backup(backup);
	return (result);
}
