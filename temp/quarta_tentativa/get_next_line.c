/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/25 20:21:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	int				bytesread;
	char			*line;

	head = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_the_buffer(fd, &head);
	bytesread = ft_lstsize(head);
	line = malloc(bytesread + 2);
	if (!line)
		return (NULL);
	join(head, line, bytesread);
	free_node(&head, bytesread);
	return (line);
}

void	read_the_buffer(int fd, t_list **head)
{
	int		bytesread;
	char	*chr;
	char	*current;

	chr = malloc(BUFFER_SIZE + 1);
	if (!chr)
		return ;
	chr[0] = '\0';
	while (!(ft_strchr(chr, '\n')))
	{
		current = chr;
		bytesread = read(fd, current, BUFFER_SIZE);
		if (bytesread < 0)
		{
			wipe_all_data(head);
			return ;
		}
		else if (bytesread == 0)
			break ;
		current[bytesread] = '\0';
		while (*current != '\0')
		{
			insert_char(&*head, *current);
			current++;
		}
	}
	free(chr);
}

void	join(t_list *head, char *line, int counter)
{
	int		count;
	t_list	*current;

	current = head;
	count = 0;
	while (count < counter && current != NULL)
	{
		line[count] = current->data;
		current = current->next;
		count++;
	}
	line[count++] = '\0';
}

void	wipe_all_data(t_list **wipe)
{
	t_list	*current;
	t_list	*next;

	current = *wipe;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*wipe = NULL;
}
