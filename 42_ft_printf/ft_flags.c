/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:59:24 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/11 16:54:27 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_c(va_list args)
{
	int	caracter;

	caracter = (char)va_arg(args, int);
	return (ft_putchar(caracter));
}

int	flag_percent(void)
{
	return (ft_putchar('%'));
}

int	flag_s(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	return (ft_putstr(string));
}

int	flag_space(void)
{
	return (ft_putstr("% "));
}

int	flag_u(va_list args, int flag)
{
	unsigned int	nbr;
	char			*number;
	int				index;
	int				counter;

	counter = 0;
	if (flag == 2)
		counter += ft_putchar('+');
	nbr = va_arg(args, unsigned int);
	index = 0;
	number = ft_itoa_unsigned(nbr);
	while (number[index])
	{
		counter += ft_putchar(number[index]);
		index++;
	}
	free(number);
	return (counter);
}
