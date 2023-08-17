/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1010.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:54:36 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/15 10:05:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_array
{
	int		numbers[2];
	float	value;
}			t_array;

int	main(void)
{
	t_array	p1;
	t_array	p2;
	float	tot;

	scanf("%d %d %f", &p1.numbers[0], &p1.numbers[1], &p1.value);
	scanf("%d %d %f", &p2.numbers[0], &p2.numbers[1], &p2.value);
	tot = ((p1.numbers[1] * p1.value) + (p2.numbers[1] * p2.value));
	printf("VALOR A PAGAR: R$ %.2f\n", tot);
	return (0);
}
