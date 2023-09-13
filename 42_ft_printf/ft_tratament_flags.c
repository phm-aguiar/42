/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tratament_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:23 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/13 10:39:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tratament_flags(char string, va_list args)
{
	int	counter;

	counter = 0;
	if (string == 'c')
		counter = flag_c(args);
	else if (string == '%')
		counter = flag_percent();
	else if (string == 'p')
		counter = flag_p(args);
	else if (string == 's')
		counter = flag_s(args);
	else if (string == 'd' || string == 'i')
		counter = flag_di(args);
	else if (string == 'u')
		counter = flag_u(args);
	else if (string == 'x')
		counter = flag_x(args);
	else if (string == 'X')
		counter = flag_x2(args);
	else if (string == ' ')
		counter = flag_space();
	return (counter);
}
