/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/23 18:38:59 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*head;
	int				bytesread;
	int				counter;
	char			chr;

	head = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &chr, 0) < 0)
		return (NULL);
	bytesread = 1;
	counter = 0;
	while (bytesread)
	{
		bytesread = read(fd, &chr, 1);
		if (bytesread <= 0 || chr == '\n' || chr == '\0')
			break ;
		counter++;
		insert_char(&head, chr);
	}
	return (join(&head));
}

void	insert_char(t_node **head, char character)
{
	t_node	*current;
	t_node	*new_node;

	if (*head == NULL)
	{
		*head = (t_node *)malloc(sizeof(t_node));
		if (*head == NULL)
			return ;
		(*head)->data = character;
		(*head)->next = NULL;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		new_node = (t_node *)malloc(sizeof(t_node));
		if (new_node == NULL)
			return ;
		new_node->data = character;
		new_node->next = NULL;
		current->next = new_node;
	}
}

char	*join(t_node **head)
{
	char	*line;
	int		count;
	t_node	*current;
	int		i;

	count = 0;
	i = 0;
	current = *head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	line = (char *)malloc((count + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	current = *head;
	while (current != NULL)
	{
		line[i] = current->data;
		current = current->next;
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
