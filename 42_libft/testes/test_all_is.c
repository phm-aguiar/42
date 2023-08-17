/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:06:21 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 19:22:23 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_isdigit(void)
{
	int	result3;
	int	result4;

	result3 = !!isdigit('1');
	result4 = ft_isdigit('1');
	return (comparetestresults("isdigit", result3, result4));
}

bool	test_isalnum(void)
{
	int	result5;
	int	result6;

	result5 = !!isalnum('A');
	result6 = ft_isalnum('A');
	return (comparetestresults("isalnum", result5, result6));
}

bool	test_isascii(void)
{
	int	result8;
	int	result7;

	result7 = !!isascii(65);
	result8 = ft_isascii(65);
	return (comparetestresults("isascii", result7, result8));
}

bool	test_isprint(void)
{
	int	result9;
	int	result10;

	result9 = !!isprint('A');
	result10 = ft_isprint('A');
	return (comparetestresults("isprint", result9, result10));
}
