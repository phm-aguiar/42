/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:20:21 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 19:20:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_tolower(void)
{
	int	result15;
	int	result16;

	result15 = tolower('A');
	result16 = ft_tolower('A');
	return (comparetestresults("tolower", result15, result16));
}
