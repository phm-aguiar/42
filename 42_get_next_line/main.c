/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:40:48 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/24 18:30:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	free_node(t_list *wipe, int counter)
{
	t_list	*current;
	t_list	*next;

	current = wipe;
	while (1)
	{
		if (counter == 0)
			break ;
		next = current->next;
		free(current);
		current = next;
		counter--;
	}
wipe = NULL;
}

void	insert_char(t_list **head, char character)
{
	t_list	*current;
	t_list	*new_node;

	if (*head == NULL)
	{
		*head = (t_list *)malloc(sizeof(t_list));
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
		new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node == NULL)
			return ;
		new_node->data = character;
		new_node->next = NULL;
		current->next = new_node;
	}
}

int	ft_strlen(const char *msg)
{
	int	counter;

	counter = 0;
	while (msg[counter])
		counter++;
	return (counter);
}

int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->data != '\n' && lst->next && count++)
		lst = lst->next;
	return (count);
}
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
	int		bolean;

	bolean = 0;
	chr = malloc(BUFFER_SIZE + 1);
	if (!chr)
		return ;
	bytesread = read(fd, chr, BUFFER_SIZE);
	if (bytesread <= 0)
	{
		free(chr);
		return ;
	}
	chr[bytesread] = '\0';
	while (*chr != '\0')
	{
		if (*chr != '\n')
			bolean = 1;
		insert_char(&*head, *chr);
		chr++;
	}
	if (bolean)
		read_the_buffer(fd, &*head);
	else
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

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teste.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		usleep(50000);
		free(line);
	}
	return (0);
}
