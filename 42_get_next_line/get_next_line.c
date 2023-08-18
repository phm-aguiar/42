/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:24:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/18 12:00:33 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*extract_line(t_list **head)
{
	t_list	*complete_line;
	char	*line;

	complete_line = *head;
	if (complete_line)
	{
		line = ft_strdup(complete_line->line);
		if (!line)
			return (NULL);
		*head = complete_line->next;
		free(complete_line->line);
		free(complete_line);
		return (line);
	}
	return (NULL);
}

static void	cleanup_and_return(t_list **head, char *line)
{
	ft_lstclear(head);
	free(line);
}

static void	ft_processing_buffer(t_alldata *gnl, t_list **head)
{
	t_list	*new_node;

	if (!ft_strchr(gnl->newline, '\n'))
	{
		new_node = ft_lstnew(gnl->newline);
		if (new_node)
			ft_lstadd_back(head, new_node);
	}
}

char	*get_next_line(int fd)
{
	t_alldata		gnl;
	static t_list	*head = NULL;

	if (!head)
	{
		head = ft_lstnew("");
		if (!head)
			return (NULL);
	}
	gnl.newline = (char *)malloc(BUFFER_SIZE + 1);
	if (!gnl.newline)
		return (NULL);
	gnl.bytesread = read(fd, gnl.newline, BUFFER_SIZE);
	if (gnl.bytesread <= 0)
	{
		free(gnl.newline);
		if (gnl.bytesread < 0)
			return (NULL);
		cleanup_and_return(&head, NULL);
	}
	gnl.newline[gnl.bytesread] = '\0';
	ft_processing_buffer(&gnl, &head);
	gnl.line = extract_line(&head);
	free(gnl.newline);
	return (gnl.line);
}
