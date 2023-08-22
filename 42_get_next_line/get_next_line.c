/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:42:08 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/22 13:25:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_gnl			gnl;

	head = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &gnl.line, 0) < 0)
		return (NULL);
	gnl.bytesread = 1;
	gnl.line = NULL;
	read_and_stash(&head, &gnl.bytesread, fd);
	if (!head)
		return (NULL);
	extract_line(head, &gnl.line);
	clean_head(&head);
	if (gnl.line[0] == '\0')
	{
		free_head(head);
		head = NULL;
		return (NULL);
	}
	return (gnl.line);
}

void	read_and_stash(t_list **head, int *ptr_bytes, int fd)
{
	t_gnl	ras;

	while (!found_newline(*head) && *ptr_bytes != 0)
	{
		ras.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!ras.buffer)
			return ;
		*ptr_bytes = (int)read(fd, ras.buffer, BUFFER_SIZE);
		if ((*head == NULL && *ptr_bytes == 0) || *ptr_bytes == -1)
		{
			free(ras.buffer);
			return ;
		}
		ras.buffer[*ptr_bytes] = '\0';
		add_to_head(head, ras.buffer, *ptr_bytes);
		free(ras.buffer);
	}
}

void	add_to_head(t_list **head, char *buff, int ptr_bytes)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = malloc((ptr_bytes + 1) * sizeof(char));
	if (!new_node->data)
		return ;
	i = 0;
	while (buff[i] && i < ptr_bytes)
	{
		new_node->data[i] = buff[i];
		i++;
	}
	new_node->data[i] = '\0';
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last = ft_lst_get_last(*head);
	last->next = new_node;
}

void	extract_line(t_list *head, char **line)
{
	int	i;
	int	j;

	if (head == NULL)
		return ;
	generate_line(line, head);
	if (!*line)
		return ;
	j = 0;
	while (head)
	{
		i = 0;
		while (head->data[i])
		{
			if (head->data[i] == '\n')
			{
				(*line)[j++] = head->data[i];
				break ;
			}
			(*line)[j++] = head->data[i++];
		}
		head = head->next;
	}
	(*line)[j] = '\0';
}

void	clean_head(t_list **head)
{
	t_list	*clean_node;
	t_list	*last;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*head);
	i = 0;
	while (last->data[i] && last->data[i] != '\n')
		i++;
	if (last->data && last->data[i] == '\n')
		i++;
	clean_node->data = malloc((ft_strlen(last->data) - i + 1) * sizeof(char));
	if (!clean_node->data)
		return ;
	j = 0;
	while (last->data[i])
		clean_node->data[j++] = last->data[i++];
	clean_node->data[j] = '\0';
	free_head(*head);
	*head = clean_node;
}
