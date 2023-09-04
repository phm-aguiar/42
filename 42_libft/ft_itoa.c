/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:01:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/10 15:47:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_data	ft_memory_and_counter_itoa(long nbr)
{
	t_data	data_base;

	data_base.counter = 0;
	if (nbr == 0)
		data_base.counter = 1;
	else if (nbr < 0)
	{
		nbr = -nbr;
		data_base.counter++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		data_base.counter++;
	}
	data_base.memory = (char *)malloc((data_base.counter + 1) * sizeof(char));
	if (data_base.memory == NULL)
		return (data_base);
	data_base.memory[data_base.counter] = '\0';
	return (data_base);
}

char	*ft_itoa(int n)
{
	t_data	data_base;
	long	nbr;

	nbr = (long)n;
	data_base = ft_memory_and_counter_itoa(nbr);
	if (data_base.memory == NULL)
		return (NULL);
	if (n == 0)
	{
		data_base.memory[0] = '0';
		return (data_base.memory);
	}
	if (n < 0)
	{
		data_base.memory[0] = '-';
		nbr = -nbr;
	}
	while (data_base.counter > (data_base.memory[0] == '-'))
	{
		data_base.memory[--data_base.counter] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (data_base.memory);
}
