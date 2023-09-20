/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jaime Nevado <jaimenevadof@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:52 by jaimenevado       #+#    #+#             */
/*   Updated: 2023/09/20 18:42:57 by Jaime Nevad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_empty_line(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char *ft_read_file(int fd, int *readed, char **lines)
{
	char *buffer;
	char *save;

	buffer = (char *)malloc(((BUFFER_SIZE) + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (*readed > 0)
	{
		*readed = read(fd, buffer, BUFFER_SIZE);
		if (*readed == -1)
		{
			ft_empty_line(&buffer);
			return (NULL);
		}
		buffer[*readed] = '\0';
		save = ft_strjoin(*lines, buffer);
		ft_empty_line(lines);
		if (ft_strchr(save, '\n') || (*readed == 0))
			break;
		*lines = ft_strjoin(save, NULL);
		ft_empty_line(&save);
	}
	*lines = ft_store_line(save);
	ft_empty_line(&buffer);
	return (save);
}

char *ft_store_line(const char *str)
{
	char *store_line;
	char *first_part;

	if (!str)
		return (NULL);
	first_part = ft_strchr(str, '\n');
	if (first_part)
	{
		if (*(first_part + 1) != '\0')
			store_line = ft_strjoin(first_part + 1, NULL);
		else
			store_line = NULL;
		return (store_line);
	}
	else
		return (NULL);
}

char *ft_get_line(const char *str)
{
	char *solution;
	char *first_part;
	int lenght_1;
	int lenght_2;

	if (str == NULL)
		return (NULL);
	first_part = ft_strchr(str, '\n');
	if (first_part)
	{
		lenght_1 = ft_strlen(str);
		if (*(first_part + 1) != '\0')
			lenght_2 = ft_strlen(first_part + 1);
		else
			lenght_2 = 0;
		solution = (char *)malloc(((lenght_1 - lenght_2) + 1) * sizeof(char));
		if (solution == NULL)
			return (NULL);
		ft_strlcpy(solution, str, ((lenght_1 - lenght_2 + 1)));
		return (solution);
	}
	solution = ft_strjoin(str, NULL);
	return (solution);
}

char *get_next_line(int fd)
{
	static char *lines;
	char *first_part;
	char *line_sol;
	int readed;

	readed = 1;
	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	first_part = ft_read_file(fd, &readed, &lines);
	if (readed == -1)
	{
		ft_empty_line(&lines);
		return (NULL);
	}
	line_sol = ft_get_line(first_part);
	ft_empty_line(&first_part);
	if ((line_sol) && (*line_sol == '\0'))
	{
		ft_empty_line(&line_sol);
		ft_empty_line(&lines);
	}
	return (line_sol);
}
