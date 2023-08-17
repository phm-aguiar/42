/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1012.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:58:24 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/16 18:36:25 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	ci;
	double	tr;
	double	qu;
	double	re;

	scanf("%lf %lf %lf", &a, &b, &c);
	t = (a * c) / 2;
	ci = 3.14159 * c * c;
	tr = ((a + b) * c) / 2;
	qu = a * a;
	re = a * b;
	printf("TRIANGULO: %.3lf\n", t);
	printf("CIRCULO: %.3lf\n", ci);
	printf("TRAPEZIO: %.3lf\n", tr);
	printf("QUADRADO: %.3lf\n", qu);
	printf("RETANGULO: %.3lf\n", re);
	return (0);
}
