/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	extract_line(t_list **list_of_char, char **line, int counter)
{
	t_list	*current;
	int		index;

	current = *list_of_char;
	index = 0;
	while (index < counter && current != NULL)
	{
		(*line)[index] = current->data;
		current = current->next;
		index++;
	}
	(*line)[index] = '\0';
}

void	add_caracter(t_list **main_list, char character)
{
	t_list	*new_node;
	t_list	*current;

	if (main_list == NULL || *main_list == NULL)
		return ;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->data = character;
	new_node->next = NULL;
	current = *main_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	split_char(const char *c, t_list **main_list)
{
	int	bol;

	bol = 1;
	while (*c)
	{
		if (*c == '\n')
			bol = 0;
		if (*main_list == NULL)
		{
			start_list(main_list, *c);
			c++;
			continue ;
		}
		add_caracter(main_list, *c);
		c++;
	}
	return (bol);
}

int	read_the_file(int fd, t_list **main_list)
{
	int		bytesread;
	char	*current;

	current = malloc(BUFFER_SIZE + 1);
	if (!current)
		return (1);
	bytesread = 1;
	while (bytesread)
	{
		bytesread = read(fd, current, BUFFER_SIZE);
		if (bytesread < 0)
		{
			wipe(main_list, -1);
			*main_list = NULL;
			free(current);
			return (1);
		}
		if (bytesread == 0)
		{
			free(current);
			return (1);
		}
		current[bytesread] = '\0';
		if (split_char(current, main_list) == 0)
			bytesread = 0;
	}
	free(current);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*main_list;
	char			*line;
	int				counter;
	int				boolean;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	boolean = read_the_file(fd, &main_list);
	if (boolean && !main_list)
	{
		wipe(&main_list, -1);
		return (NULL);
	}
	counter = ftsizelst(&main_list);
	line = malloc(counter + 1);
	if (!line)
	{
		wipe(&main_list, -1);
		return (NULL);
	}
	extract_line(&main_list, &line, counter);
	wipe(&main_list, counter);
	return (line);
}
