/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:24:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/17 16:36:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		reader;
	t_list		abracadabra;

	abracadabra = ft_lstnew(buffer);
	while (buffer)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	return (buffer);
}

int	main(void)
{
	ssize_t	fd;
	char	*oi;

	fd = open("test.txt", O_RDONLY);
	oi = get_next_line(fd);
	if (oi)
		write(1, oi, ft_strlen(oi));
	free(oi);
	close(fd);
}
