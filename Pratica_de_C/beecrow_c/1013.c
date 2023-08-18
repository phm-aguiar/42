/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1013.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:50:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/16 21:57:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	maior;

	scanf("%d %d %d", &a, &b, &c);
	maior = a;
	if (b > maior)
		maior = b;
	if (c > maior)
		maior = c;
	printf("%d eh o maior\n", maior);
	return (0);
}
