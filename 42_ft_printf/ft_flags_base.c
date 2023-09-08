/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:13:03 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/08 14:49:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	flag_di(va_list args)
{
	size_t	counter;

	counter = 0;
	counter = ft_putnbr_base(va_arg(args, int), "0123456789");
	return (counter);
}

int	flag_p(va_list args)
{
	size_t	ptr;
	int		counter;

	counter = 0;
	ptr = va_arg(args, size_t);
	counter += ft_putptr(ptr, "0123456789abcdef");
	return (counter);
}

int	flag_x(va_list args)
{
	unsigned int	nbr;
	int				counter;

	counter = 0;
	nbr = va_arg(args, unsigned int);
	counter = ft_putnbr_base(nbr, "0123456789abcdef");
	return (counter);
}

int	flag_x2(va_list args)
{
	unsigned int	nbr;
	int				counter;

	counter = 0;
	nbr = va_arg(args, unsigned int);
	counter = ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (counter);
}
