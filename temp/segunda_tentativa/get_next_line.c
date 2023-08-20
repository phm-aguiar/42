/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:24:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/19 19:11:49 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_add_incomplete_line(t_alldata *gnl, t_list **head)
{
	t_list	*new_node;

	if (!ft_strchr(gnl->buffer, '\n'))
	{
			while (!ft_strchr(gnl->buffer, '\n'))
	{
		new_node = ft_lstnew(gnl->buffer);
		if (new_node)
			ft_lstadd_back(head, new_node);
	}
		new_node = ft_lstnew(gnl->buffer);
		if (new_node)
			ft_lstadd_back(head, new_node);
	}
}

static char	*ft_get_complete_line(t_alldata *gnl, t_list **head)
{
	t_list	*complete_line;

	complete_line = *head;
	if (complete_line)
	{
		// caçar a raba len ate raba criar string e mallocar deletar tudo que nao precisa
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	t_alldata		gnl;

	if (fd < 0)
		return (NULL);
	gnl.bytesread = read(fd, gnl.buffer, BUFFER_SIZE);
	if (gnl.bytesread <= 0)
	{
		if (gnl.bytesread < 0)
		{
			ft_lstclear(&head);
			return (NULL);
		}
	}
	gnl.buffer[gnl.bytesread] = '\0';
	ft_add_incomplete_line(&gnl, &head);
	gnl.end = ft_get_complete_line(&gnl, &head);
	ft_lstclear(&head);
	return (gnl.end);
}
