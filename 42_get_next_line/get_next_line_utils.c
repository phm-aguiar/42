/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:31:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/20 18:50:28 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_node *head)
{
	int		i;
	t_node	*current;

	if (!head)
		return (0);
	current = ft_lst_get_last(head);
	i = 0;
	while (current->data[i])
	{
		if (current->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_node	*ft_lst_get_last(t_node *head)
{
	t_node	*current;

	current = head;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate_line(void)
{
	return ;
}

void	free_head(void)
{
	return ;
}
