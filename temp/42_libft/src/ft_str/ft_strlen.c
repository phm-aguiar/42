/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:20:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/04 17:45:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_strlen(const char *msg)
{
	int	counter;

	counter = 0;
	while (msg[counter])
		counter++;
	return (counter);
}
