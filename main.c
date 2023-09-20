/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jaime Nevado <jaimenevadof@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:52 by jaimenevado       #+#    #+#             */
/*   Updated: 2023/09/20 18:50:33 by Jaime Nevad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	char file_name[] = "text.txt";
	int fd = open(file_name, O_RDONLY);

	// Cada vez que se llame a get_next_line() escribirá la linea siguiente
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
	return 0;
}