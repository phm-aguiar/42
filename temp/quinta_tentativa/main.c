/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:27:16 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/27 14:27:51 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 1;
	fd = open("teste.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha %d: %s", line_number, line);
		line_number++;
		free(line);
	}
	close(fd);
	return (0);
}
