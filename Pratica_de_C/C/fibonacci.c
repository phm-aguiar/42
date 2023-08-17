/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:57:20 by phenriq2          #+#    #+#             */
/*   Updated: 2023/06/23 10:57:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	fibonacci(int posicao)
{
	if (posicao <= 1)
		return (posicao);
	else
		return (fibonacci(posicao - 1) + fibonacci(posicao - 2));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int	main(void)
{
	int	counter;
	int	i;

	counter = 10;
	i = 0;
	while (i < counter)
	{
		ft_putnbr(fibonacci(i));
		if (i != counter - 1)
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
	return (0);
}
