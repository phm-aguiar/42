/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:32:12 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/05 09:49:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_putnbr_base(long nbr, char *base)
{
	int	len;
	int	len_read;

	len_read = 0;
	if (!base)
		return (0);
	len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -nbr;
		len_read++;
		ft_putchar_fd('-', 1);
	}
	while (nbr >= len)
	{
		len_read++;
		ft_putchar_fd(base[nbr % len], 1);
		nbr = nbr / len;
	}
	ft_putchar_fd(base[nbr], 1);
	return (len_read);
}
