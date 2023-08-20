/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:42:08 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/20 09:02:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

// https://www.youtube.com/watch?v=xgDSXNOHTIA&ab_channel=nikito
char	*get_next_line(int fd)
{
	static t_node	*head;
	t_gnl			gnl;

	head = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &gnl.line, 0) < 0)
		return (NULL);
	gnl.bytesread = 1;
	gnl.line = NULL;
	// ler do fd e jogar na lista linkada
	// extrair da lista head para a linha
	// limpar a lista
	return (gnl.line);
}

void	read_and_stash(void)
{
}

void	add_to_stash(void)
{
}

void	extract_line(void)
{
}

void	clean_stash(void)
{
}
