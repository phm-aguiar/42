/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/30 17:58:19 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_extract_line(t_list **list_of_char, char **line, int counter)
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

void	ft_add_caracter(t_list **main_list, char character)
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

int	ft_split_char(const char *c, t_list **main_list)
{
	int	bol;

	bol = 1;
	while (*c)
	{
		if (*c == '\n')
			bol = 0;
		if (*main_list == NULL)
		{
			ft_start_list(main_list, *c);
			c++;
			continue ;
		}
		ft_add_caracter(main_list, *c);
		c++;
	}
	return (bol);
}

int	ft_read_the_file(int fd, t_list **main_list)
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
			return (ft_read_error(main_list, current));
		if (bytesread == 0)
		{
			free(current);
			return (1);
		}
		current[bytesread] = '\0';
		if (ft_split_char(current, main_list) == 0)
			bytesread = 0;
	}
	free(current);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*main_list[2048];
	char			*line;
	int				counter;
	int				boolean;

	if (fd >= 0 && BUFFER_SIZE >= 0 )
		boolean = ft_read_the_file(fd, &main_list[fd]);
	if ((fd < 0) && !main_list[fd])
		return (NULL);
	if (boolean && !main_list[fd])
	{
		ft_wipe_list(&main_list[fd], -1);
		return (NULL);
	}
	counter = ft_sizelst(&main_list[fd]);
	line = malloc(counter + 1);
	if (!line)
	{
		ft_wipe_list(&main_list[fd], -1);
		return (NULL);
	}
	ft_extract_line(&main_list[fd], &line, counter);
	ft_wipe_list(&main_list[fd], counter);
	return (line);
}
