/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:49:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/10 14:08:46 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	counter;
	int		issing;
	int		result;

	counter = 0;
	result = 0;
	issing = 1;
	while ((((nptr[counter] >= 9) && (nptr[counter] <= 13))
			|| ((nptr[counter]) == 32)))
		counter++;
	if ((nptr[counter] == '-') || (nptr[counter] == '+'))
	{
		if ((nptr[counter] == '-'))
			issing *= -1;
		counter++;
	}
	while (nptr[counter] >= '0' && nptr[counter] <= '9')
	{
		result = result * 10 + (nptr[counter] - '0');
		counter++;
	}
	result *= issing;
	return (result);
}
