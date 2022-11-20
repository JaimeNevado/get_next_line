/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:52 by jaimenevado       #+#    #+#             */
/*   Updated: 2022/11/20 19:12:48 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_line(const char *buff)
{
	int	i;
	char	*solution;
	int	line_lenght;

	line_lenght = 0;
	while (buff[line_lenght] != '\0' && buff[line_lenght] != '\n')
	{
		line_lenght++;
	}
	if (buff[line_lenght] == '\n')
		line_lenght++;
	solution = (char *) malloc(sizeof(char) * (line_lenght + 1));
	if (solution == NULL)
		return (NULL);
	i = 0;
	while (i < line_lenght)
	{
		solution[i] = buff[i];
		i++;
	}
	solution[i] = '\0';
	return (solution);
}

char	*ft_clean_buffer(char *buff)
{
	int		longitud_linea;
	int		longitud_resto;
	int		i;
	int		j;
	char	*result;

	longitud_linea = 0;
	longitud_resto = 0;

	while (buff[longitud_linea] != 0 && buff[longitud_linea] != '\n')
		longitud_linea++;
	if (buff[longitud_linea] == '\n')
		longitud_linea++;
	while(buff[longitud_linea + longitud_resto])
		longitud_resto++;
	result = (char *) malloc ((sizeof(char) * longitud_resto) + 1);
	if (result == NULL)
		return (NULL);
//	printf("Debe meter '%s' de '%s' \n", &buff[longitud_linea], buff);
	result[longitud_resto] = '\0';
	i = 0;
	j = longitud_linea + 1; // Comprobar que no se ha salido
	while (buff[j] != '\0')
	{
		result[i] = buff[j + i];
		i++;
	}
	result[i] = '\0';
	free (buff);
	return (result);
}

int	ft_check_line(char *buff)
{
	int	i;

	if(!buff)
		return (0);
	i = 0;
	while (buff[i])		//dos buff por si hay segmentation fault
	{
		if (buff[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

char	*get_next_line(int fd)
{
	static char	*resto;
	char		*buff;
	char		*linea;
	int			leido;

	if(BUFFER_SIZE < 1 || fd > 0)
		return (NULL);
	buff = (char *) malloc((BUFFER_SIZE +1) * sizeof(char));
	if (buff == NULL)
	{
		if (resto)
			free(resto);
		return (NULL);
	}
	linea = NULL;
	leido = 1;
	if (!resto)
	{
		resto = (char *) malloc(sizeof(char));
		resto[0] = '\0';
	}
	while ((!ft_check_line(resto)) && (leido > 0))
	{
		leido = read(fd, buff, BUFFER_SIZE);
		buff[leido] = '\0';
	//	printf("Bytes leídos - %d; Buffer - %s\n", leido, buff);
		if (leido == -1)
		{
			free(buff);
			free(resto);
			return (NULL);
		}

		if (resto || buff)
			resto = ft_strjoin(resto, buff);
		if (resto == NULL)
		{
			free(buff);
			free(resto);
			return (NULL);
		}
	}
	linea = ft_get_line(resto);
	resto = ft_clean_buffer(resto);
	free(buff);
	if (!linea || !resto)
		return (NULL);
//	printf("Resto = %s\n", resto);
	return (linea);
}


//  int     main(void)
// {
//     int     fd;

//     fd = open("text.txt",  O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }
