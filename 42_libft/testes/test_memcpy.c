/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:20:13 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/25 12:01:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_memcpy(void)
{
	char	src[5] = "Hello";
	char	dest1[5];
	char	dest2[5];

	memcpy(dest1, src, 5);
	ft_memcpy(dest2, src, 5);
	return (comparetestresults("memcpy", memcmp(dest1, dest2, 5), 0));
}
