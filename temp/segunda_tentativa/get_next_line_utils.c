/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:25:00 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/18 19:43:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		counter;
	char	*copy;

	counter = 0;
	while (src[counter] != '\0')
		counter++;
	copy = malloc(counter + 1);
	if (copy == NULL)
		return (NULL);
	counter = 0;
	while (src[counter] != '\0')
	{
		copy[counter] = src[counter];
		counter++;
	}
	copy[counter] = '\0';
	return (copy);
}

t_list	*ft_lstnew(const char *line)
{
	t_list	*new_line;

	new_line = malloc(sizeof(t_list));
	if (!new_line)
		return (0);
	new_line->line = (char *)line;
	new_line->next = 0;
	return (new_line);
}

void	ft_lstadd_back(t_list **lst, t_list *new_line)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new_line;
		return ;
	}
	last = *lst;
	while (last && last->next)
		last = last->next;
	last->next = new_line;
}

void	ft_lstdelone(t_list **lst, t_list *node)
{
	if (!lst || !node)
		return ;
	free(node->line);
	free(node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next_list;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next_list = current->next;
		ft_lstdelone(lst, current);
		current = next_list;
	}
}
