/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:52 by jaimenevado       #+#    #+#             */
/*   Updated: 2022/11/19 20:12:38 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(const char *buff, int leido)
{
	int	i;
	char	*solution;

	solution = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (solution == NULL)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n' && i < BUFFER_SIZE)
	{
		solution[i] = buff[i];
		i++;
	}
	return (solution);
}

char	*ft_clean_buffer(const char *buff, char *str)
{
	int		i;
	int		j;
	char	*result;
	
	j = 0;
	i = ft_strlen(str);
	result = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (result == NULL)
		return (NULL);
	while (i < BUFFER_SIZE)
	{
		result[j] = buff[i];
		i++;
		j++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*s1;
	static char	*buff;
	int			leido;
	int			i;

	i = 0;
	//Reserva de memoria

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	s1 = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (s1 == NULL)
		return (NULL);
	leido = BUFFER_SIZE;
	while (buff[i] != '\0')
	{
		leido = read(fd, buff, BUFFER_SIZE);
		if (ft_strchr(buff, '\n'))
			s1 = ft_strjoin(s1, buff);
	}

	return (s1);
}


 int     main(void)
{
    int     fd;
    fd = open("text.txt",  O_RDONLY);
	
	printf("\n%s", get_next_line(fd));
	return (0);
}
