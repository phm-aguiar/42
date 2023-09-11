/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:32:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 17:06:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tratament_flags(const char *string, va_list args)
{
	int	counter;

	counter = 0;
	if (*string == 'c')
		counter = flag_c(args);
	else if (*string == '%')
		counter = flag_percent();
	else if (*string == 'p')
		counter = flag_p(args);
	else if (*string == 's')
		counter = flag_s(args);
	else if (*string == 'd' || *string == 'i')
		counter = flag_di(args);
	else if (*string == 'u')
		counter = flag_u(args);
	else if (*string == 'x')
		counter = flag_x(args);
	else if (*string == 'X')
		counter = flag_x2(args);
	else if (*string == ' ')
		counter = flag_space();
	return (counter);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		bytes;
	int		index;

	index = 0;
	bytes = 0;
	va_start(args, string);
	while (string[index] != '\0')
	{
		if (string[index] == '%')
		{
			index++;
			bytes += tratament_flags(&string[index], args);
		}
		else
			bytes += ft_putchar(string[index]);
		index++;
	}
	va_end(args);
	return (bytes);
}
