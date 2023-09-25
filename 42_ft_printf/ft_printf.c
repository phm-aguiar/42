/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:32:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/25 11:48:27 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
				flag = tratament_flags_advanced(string[index], &index);
			bytes += tratament_flags(string[index], args, flag);
		}
		else
			bytes += ft_putchar(string[index]);
		index++;
	}
	va_end(args);
	return (bytes);
}
