/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:14:22 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/04 17:43:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_bzero(void *array, size_t num)
{
	char	*temp;
	size_t	counter;

	temp = (char *)array;
	counter = 0;
	while (counter < num)
	{
		temp[counter] = '\0';
		counter++;
	}
}
