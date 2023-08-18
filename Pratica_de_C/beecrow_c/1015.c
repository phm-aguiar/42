/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1015.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:39:33 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/16 22:39:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

float	ft_sqrt(float nb)
{
	float	low;
	float	high;
	float	mid;
	float	precision;

	if (nb <= 0)
		return (0);
	low = 0;
	high = nb;
	mid = (low + high) / 2.0;
	precision = 0.00001;
	while (high - low > precision)
	{
		mid = (low + high) / 2.0;
		if (mid * mid > nb)
			high = mid;
		else
			low = mid;
	}
	return (mid);
}

int	main(void)
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	ext;

	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	ext = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
	printf("%.4f\n", ft_sqrt(ext));
	return (0);
}
