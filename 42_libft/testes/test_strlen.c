/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:17:55 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 19:18:19 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_strlen(void)
{
	size_t	result11;
	size_t	result12;

	result11 = strlen("Hello");
	result12 = ft_strlen("Hello");
	return (comparetestresults("strlen", (int)result11, (int)result12));
}
