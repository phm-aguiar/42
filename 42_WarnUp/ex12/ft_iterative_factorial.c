/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/12 14:43:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fatorial;

	fatorial = nb;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	else
	{
		if (nb == 0)
			return (1);
		while (nb != 1)
		{
			fatorial *= (nb - 1);
			nb--;
		}
		return (fatorial);
	}
}
