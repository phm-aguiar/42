/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:22:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/27 20:04:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_size_lst(t_list **list_of_char)
{
	t_list	*size;
	int		counter;

	size = *list_of_char;
	counter = 0;
	while (size != NULL && size->data != '\n')
	{
		counter++;
		size = size->next;
	}
	return (counter);
}

void	create_empty_list(t_list **current)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list != NULL)
	{
		new_list->data = '\0';
		new_list->next = NULL;
		*current = new_list;
	}
}

void	insert_into_list(t_list **head, char character)
{
	t_list	*new_node;
	t_list	*current;

	if (head == NULL || *head == NULL)
		return ;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->data = character;
	new_node->next = NULL;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	free_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
