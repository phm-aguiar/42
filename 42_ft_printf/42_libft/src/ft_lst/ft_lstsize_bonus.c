/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:58 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/04 17:43:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->next && count++)
		lst = lst->next;
	return (count);
}
