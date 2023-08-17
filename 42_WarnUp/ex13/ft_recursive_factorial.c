/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:22:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/12 15:33:08 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fatorial;

	fatorial = nb;
	if (nb < 0 || nb > 12)
		return (0);
	else
	{
		if (nb == 1 || nb == 0)
			return (1);
		fatorial *= ft_recursive_factorial(nb - 1);
		return (fatorial);
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_recursive_factorial(-2));
// }
