/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:46:26 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/13 17:57:51 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char *x)
{
    size_t i;
    char *line;

    i = 0;
    while (x[i++] != '\n');
    line = malloc(sizeof(char) * (i + 1));
    line[i + 1] = '\0';
    while (i--)
        line[i] = x[i];
    return (line);
}
static char	*get_newline_chr(int fd, char *backup)
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
char *get_next_line(int fd)
{
    static char *backup;
    char *result;
    char *temp;

    if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup)
		return (NULL);
    if (ft_strchr(backup, '\n'))
    {
        result = get_line(backup);
        temp = ft_strdup(ft_strchr(backup, '\n') + 1);
        free(backup);
        backup = temp;
    }
    else
    {
        backup = get_newline_chr(fd, backup);
        result = get_line(backup);
        temp = ft_strdup(ft_strchr(backup, '\n') + 1);
        free(backup);
        backup = temp;
    }

    return (result);
}

