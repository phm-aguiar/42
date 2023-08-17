/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:16:15 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/26 15:28:12 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_atoi(void)
{
	const char	*str15;
	int			result29;
	int			result30;

	str15 = "-2147483648";
	result29 = atoi(str15);
	result30 = ft_atoi(str15);
	return (comparetestresults("atoi", result29, result30));
}
