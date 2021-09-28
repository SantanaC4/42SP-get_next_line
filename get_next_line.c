/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:46:26 by edrodrig          #+#    #+#             */
/*   Updated: 2021/09/28 19:41:49 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buff;
	char val;
	unsigned char i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));	
	if (buff == NULL)
		return (NULL);

	i = 0;
	while (read(fd, &val, 1) > 0)
	{
		if (val != '\n')
		{
			buff[i] = val;
			i++;
		}
		else
		{
			buff[i + 1] = '\0';
			break;
		}
	}
	return (buff);
}
