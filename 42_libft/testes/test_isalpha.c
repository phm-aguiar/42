/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:42:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 14:42:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_isalpha(void)
{
	int	result1;
	int	result2;

	result1 = !!isalpha('A');
	result2 = ft_isalpha('A');
	return (comparetestresults("isalpha", result1, result2));
}
