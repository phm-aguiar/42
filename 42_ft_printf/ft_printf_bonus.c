/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:32:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/10 08:34:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	tratament_flags(char chr, va_list args)
{
	int	counter;

	counter = 0;
	if (chr == 'c')
		counter = flag_c(args);
	else if (chr == '%')
		counter = flag_percent();
	else if (chr == 'p')
		counter = flag_p(args);
	else if (chr == 's')
		counter = flag_s(args);
	else if (chr == 'd' || chr == 'i')
		counter = flag_di(args);
	else if (chr == 'u')
		counter = flag_u(args);
	else if (chr == 'x')
		counter = flag_x(args);
	else if (chr == 'X')
		counter = flag_x2(args);
	else if (chr == ' ')
		counter = flag_space();
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
			flag = tratament_flags_advanced(&string, &index, &bytes);
			bytes += tratament_flags(string[index], args);
		}
		else
			bytes += ft_putchar(string[index]);
		index++;
	}
	va_end(args);
	return (bytes);
}
