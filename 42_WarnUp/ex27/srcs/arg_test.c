/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:16:22 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:33 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

void	arg_test(int arguments)
{
	if (arguments == 1)
	{
		write(2, "File name missing.\n", 19);
	}
	else
	{
		write(2, "Too many arguments.\n", 20);
	}
}
