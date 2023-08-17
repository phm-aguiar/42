/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:53:35 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/25 17:00:12 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	test_memmove(void)
{
	char	str5[10] = "Hello";
	char	str6[10] = "Hello";

	memmove(str5 + 2, str5, 5);
	ft_memmove(str6 + 2, str6, 5);
	return (comparetestresults("memmove", strcmp(str5, str6), 0));
}
