/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:35:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/14 14:36:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	counter;
	int	counter2;

	if (min >= max)
	{
		return (NULL);
	}
	counter = max - min;
	array = malloc(counter * sizeof(int));
	counter2 = 0;
	while (counter2 != counter)
	{
		array[counter2] = min;
		min++;
		counter2++;
	}
	return (array);
}
