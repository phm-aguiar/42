/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:25:00 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/17 16:39:15 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_del(void *content)
{
	if (content)
		free(content);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

void	ft_lstdelone(t_list *lst, void (*ft_del)(void *))
{
	if (lst && ft_del)
	{
		ft_del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*ft_del)(void *))
{
	t_list	*aux;
	char	*content;

	if (!lst || !ft_del)
		return ;
	while (*lst)
	{
		content = (char *)lst;
		aux = (*lst)->next;
		ft_lstdelone(*lst, ft_del);
		*lst = aux;
	}
	*lst = NULL;
}

size_t	ft_strlen(const char *msg)
{
	int	counter;

	counter = 0;
	while (msg[counter])
		counter++;
	return (counter);
}
