/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:31:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/19 11:35:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*ft_lstnew(const char *s)
{
	t_node	*new_line;

	new_line = malloc(sizeof(t_node));
	if (!new_line)
		return (0);
	new_line->data = (char *)s;
	new_line->next = 0;
	return (new_line);
}
