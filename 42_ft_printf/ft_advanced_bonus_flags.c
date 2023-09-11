/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_bonus_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:35:31 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/10 08:36:15 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	tratament_flags_advanced(const char **chr, int *index, int *bytes)
{
	int	flag;

	flag = 0;
	if (*chr[*index] == '0')
	{
		(*index)++;
		(*bytes)++;
		flag = 1;
	}
	if (ft_isnonzero_digit(*chr[*index]))
	{
		(*index)++;
		(*bytes)++;
		flag = 2;
	}
	return (flag);
}
