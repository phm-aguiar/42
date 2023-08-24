/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:49 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/24 18:38:35 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_node(t_list **wipe, int counter)
{
	t_list	*current;
	t_list	*next;

	current = *wipe;
	while (1)
	{
		if (counter == 0)
			break ;
		next = current->next;
		free(current);
		current = next;
		counter--;
	}
	*wipe = NULL;
}

void	insert_char(t_list **head, char character)
{
	t_list	*current;

	if (head == NULL)
	{
		(*head) = (t_list *)malloc(sizeof(t_list));
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
		current->next = (t_list *)malloc(sizeof(t_list));
		if (current->next == NULL)
			return ;
		current = current->next;
		current->data = character;
		current->next = NULL;
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
