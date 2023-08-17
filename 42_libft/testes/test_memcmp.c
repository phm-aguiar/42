/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:41:06 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/25 14:44:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_memcmp(void)
{
	const char	str12[6] = "Hello";
	const char	str13[6] = "Hella";
	int			result25;
	int			result26;

	result25 = memcmp(str12, str13, 5);
	result26 = ft_memcmp(str12, str13, 5);
	return (comparetestresults("memcmp", result25, result26));
}
