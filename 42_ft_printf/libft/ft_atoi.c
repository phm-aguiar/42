/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:49:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	index;
	int		issing;
	int		result;

	index = 0;
	result = 0;
	issing = 1;
	while ((((nptr[index] >= 9) && (nptr[index] <= 13))
			|| ((nptr[index]) == 32)))
		index++;
	if ((nptr[index] == '-') || (nptr[index] == '+'))
	{
		if ((nptr[index] == '-'))
			issing *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	result *= issing;
	return (result);
}
