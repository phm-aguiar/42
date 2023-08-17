/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatebar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:38:06 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 14:40:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

void	updatebar(int progress, int total)
{
	int	barwidth;
	int	pos;
	int	counter;

	barwidth = 50;
	counter = 0;
	pos = (int)((double)progress / total * barwidth);
	printf("\r[");
	while (counter < barwidth)
	{
		if (counter < pos)
		{
			printf("=");
		}
		else if (counter == pos)
		{
			printf(">");
		}
		else
		{
			printf(" ");
		}
		counter++;
	}
	printf("] %3d%% ", (int)((double)progress / total * 100));
}
