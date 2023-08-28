/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:22:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/28 16:53:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	wipe(t_list **list_of_char, int counter)
{
	t_list	*current;
	t_list	*temp;

	current = *list_of_char;
	while (counter > 0 && current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		counter--;
	}
	*list_of_char = current;
}

int	ftsizelst(t_list **list_of_char)
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

void	start_list(t_list **caracter)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list != NULL)
	{
		new_list->data = '\0';
		new_list->next = NULL;
		*caracter = new_list;
	}
}
