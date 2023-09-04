/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:32:12 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/04 18:43:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include <unistd.h>
size_t	ft_strlen(const char *msg)
{
	int	counter;

	counter = 0;
	while (msg[counter])
		counter++;
	return (counter);
}
int	ft_putnbr_base(long nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr < len)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		ft_putnbr_base(nbr / len, base);
		write(1, &base[nbr % len], 1);
	}
	return (count);
}
#include <stdio.h>

int	main(void)
{
	long	numero;
	int		count;

	char base[] = "0123456789ABCDEF"; // Define a base hexadecimal
	numero = -42675;
	// O número que queremos imprimir na base hexadecimal
	count = ft_putnbr_base(numero, base);
	// Chamamos a função ft_putnbr_base e guardamos o valor retornado
	printf("\n");
	printf("\nTotal de caracteres impressos: %d\n", count);
	// Imprimimos o número de caracteres impressos
	return (0);
}
