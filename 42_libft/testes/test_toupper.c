/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:19:05 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 19:19:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_toupper(void)
{
	int	result13;
	int	result14;

	result13 = toupper('a');
	result14 = ft_toupper('a');
	return (comparetestresults("toupper", result13, result14));
}
