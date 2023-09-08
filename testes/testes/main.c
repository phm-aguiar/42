/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:09:52 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/07 12:42:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include "./include/libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int		a;
	int		b;
	void	*ptr;

	a = 0;
	b = 0;
	a += ft_printf("Teste: ola %cmundo uhuu\n", 'i');
	b += printf("Teste: ola %cmundo uhuu \n", 'i');
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	a += ft_printf("Teste: ola %% mundo uhuu\n");
	b += printf("Teste: ola %% mundo uhuu \n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	a += ft_printf("Teste: ola %d mundo uhuu\n", -42);
	b += printf("Teste: ola %d mundo uhuu \n", -42);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	a += ft_printf("Teste: ola %i mundo uhuu\n", -42);
	b += printf("Teste: ola %i mundo uhuu \n", -42);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	a += ft_printf("Teste: ola %u mundo uhuu\n", 42);
	b += printf("Teste: ola %u mundo uhuu \n", 42);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	a += ft_printf("Teste: ola %x mundo uhuu\n", 42);
	b += printf("Teste: ola %x mundo uhuu \n", 42);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	a += ft_printf("Teste: ola %X mundo uhuu\n", -42);
	b += printf("Teste: ola -%X mundo uhuu \n", 42);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	ptr = &a;
	a += ft_printf("Teste: Endereço do ponteiro: %p\n", ptr);
	b += printf("Teste: Endereço do ponteiro: %p\n", ptr);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("%d/%d\n", a, b);
	return (0);
}
