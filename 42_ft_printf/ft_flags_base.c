/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:13:03 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 13:49:35 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include "./include/libft.h"
#include <stddef.h>
#include <unistd.h>

int	flag_di(va_list args)
{
	long	nbr;
	char	*number;
	int		index;
	int		counter;

	counter = 0;
	index = 0;
	nbr = va_arg(args, int);
	number = ft_itoa_base(nbr, "0123456789");
	while (number[index])
	{
		counter += ft_putchar(number[index]);
		index++;
	}
	free(number);
	return (counter);
}

int	flag_p(va_list args)
{
	size_t	ptr;
	int		counter;

	counter = 0;
	ptr = va_arg(args, size_t);
	counter += ft_putptr(ptr, "0123456789abcdef");
	return (counter -1);
}

int	flag_x(va_list args)
{
	int		nbr;
	int		index;
	char	*number;
	int		counter;

	counter = 0;
	index = 0;
	nbr = va_arg(args, int);
	number = ft_itoa_base(nbr, "0123456789abcdef");
	while (number[index])
	{
		counter += ft_putchar(number[index]);
		index++;
	}
	free(number);
	return (counter);
}

int	flag_x2(va_list args)
{
	int		nbr;
	int		index;
	char	*number;
	int		counter;

	counter = 0;
	index = 0;
	nbr = va_arg(args, int);
	number = ft_itoa_base(nbr, "0123456789ABCDEF");
	while (number[index])
	{
		counter += ft_putchar(number[index]);
		index++;
	}
	free(number);
	return (counter);
}
