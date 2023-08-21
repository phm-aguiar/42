/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:42:08 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/20 20:51:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*head;
	t_gnl			gnl;

	head = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &gnl.line, 0) < 0)
		return (NULL);
	gnl.bytesread = 1;
	gnl.line = NULL;
	// ler do fd e adicionar na lista linkada
	read_and_stash(&head, &gnl.bytesread, fd);
	if (!head)
		return (NULL);

	// extrair da head para a linha
	// limpar a head
	return (gnl.line);
}

void	read_and_stash(t_node **head, int *ptr_bytes, int fd)
{
	t_gnl	ras;

	ras.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ras.buffer)
		return ;
	while (!found_newline(*head) && *read != 0)
	{
		*ptr_bytes = (int)read(fd, ras.buffer, BUFFER_SIZE);
		if ((*head == NULL && *ptr_bytes == 0) || *ptr_bytes == -1)
		{
			free(ras.buffer);
			return ;
		}
		ras.buffer[*ptr_bytes] = '\0';
		add_to_stash();
	}
}

void	add_to_head(void)
{
}

void	extract_line(void)
{
}

void	clean_head(void)
{
}
