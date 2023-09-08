/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:10:50 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/05 14:47:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_nbrlen_base(int nbr, int len_base)
{
	int	len_nbr;

	len_nbr = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len_nbr++;
	}
	while (nbr > 0)
	{
		len_nbr++;
		nbr = nbr / len_base;
	}
	return (len_nbr);
}
