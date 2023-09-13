/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tratament_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:23 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/13 11:02:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	tratament_flags_bonus_advanced(char chr, int *index)
{
	int	flag;

	flag = -42;
	if (chr == '#')
	{
		flag = 1;
	}
	else if (chr == '+')
	{
		flag = 2;
	}
	else
		flag = 4;
	(*index)++;
	return (flag);
}

int	tratament_flags_bonus(char chr, va_list args, int flag)
{
	int	counter;

	counter = 0;
	if (chr == 'c')
		counter = flag_c_bonus(args);
	else if (chr == '%')
		counter = flag_percent_bonus();
	else if (chr == 'p')
		counter = flag_p_bonus(args);
	else if (chr == 's')
		counter = flag_s_bonus(args);
	else if (chr == 'd' || chr == 'i')
		counter = flag_di_bonus(args, flag);
	else if (chr == 'u')
		counter = flag_u_bonus(args, flag);
	else if (chr == 'x')
		counter = flag_x_bonus(args, flag);
	else if (chr == 'X')
		counter = flag_x2_bonus(args, flag);
	else if (chr == ' ')
		counter = flag_space_bonus();
	return (counter);
}
