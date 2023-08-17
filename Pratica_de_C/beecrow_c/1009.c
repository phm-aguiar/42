/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1009.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:26:22 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/15 09:37:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*name;
	double	salary;
	double	money;

	name = (char *)malloc(100 * sizeof(char));
	if (!name)
		return (0);
	scanf("%s %lf %lf", name, &salary, &money);
	salary += money * 0.15;
	printf("TOTAL = R$ %.2f\n", salary);
	return (0);
}
