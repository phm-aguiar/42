/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:32:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/11 19:07:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	tratament_flags_bonus_advanced(char chr, int *index)
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

static int	tratament_flags_bonus(char chr, va_list args, int flag)
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

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		bytes;
	int		index;
	int		flag;

	index = 0;
	bytes = 0;
	va_start(args, string);
	while (string[index] != '\0')
	{
		if (string[index] == '%')
		{
			index++;
			if (ft_strchr("# +", string[index]))
				flag = tratament_flags_bonus_advanced(string[index], &index);
			bytes += tratament_flags_bonus(string[index], args, flag);
		}
		else
			bytes += ft_putchar(string[index]);
		index++;
	}
	va_end(args);
	return (bytes);
}
