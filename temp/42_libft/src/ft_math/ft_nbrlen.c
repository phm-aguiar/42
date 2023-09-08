/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:20:02 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/05 10:34:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_nbrlen(long nbr)
{
	size_t	len;

	len = 1;
	if (!nbr)
		return (len);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
