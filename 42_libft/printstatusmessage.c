/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstatusmessage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:39:18 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/19 18:06:31 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printstatusmessage(int status)
{
	const char	*color;
	const char	*message;
	int			size;

	if (status)
	{
		color = "\033[32m";
		message = "Ok: teste";
		size = 10;
	}
	else
	{
		color = "\033[31m";
		message = "Erro: 404 page not found";
		size = 25;
	}
	write(STDOUT_FILENO, color, 6);
	write(STDOUT_FILENO, message, size);
	write(STDOUT_FILENO, "\033[0m\n", 5);
}
