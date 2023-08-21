/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:31:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/21 18:04:41 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *head)
{
	int		i;
	t_list	*current;

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

t_list	*ft_lst_get_last(t_list *head)
{
	t_list	*current;

	current = head;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate_line(char **line, t_list *head)
{
	int	i;
	int	len;

	len = 0;
	while (head)
	{
		i = 0;
		while (head->data[i])
		{
			if (head->data[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		head = head->next;
	}
	*line = malloc((len + 1) * sizeof(char));
}

void	free_head(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current)
	{
		free(current->data);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
