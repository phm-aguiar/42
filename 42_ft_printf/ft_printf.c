/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:50:14 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/03 22:33:35 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include "./include/libft.h"

int	ft_printf(const char *string, ...)
{
	ft_putstr_fd(string, 1);
	return (0);
}

int	main(void)
{
	ft_printf("ola mundo");
}
