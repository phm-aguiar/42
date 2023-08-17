/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:40:44 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/25 18:52:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	compare_memchr(const char *str, int c, size_t n)
{
	const void	*result_ft;
	const void	*result_std;

	result_ft = ft_memchr(str, c, n);
	result_std = memchr(str, c, n);
	return (result_ft == result_std);
}

bool	test_memchr(void)
{
	const char	*str;
	int			c;
	size_t		n;
	bool		result;

	str = "Hello, world!";
	c = 'w';
	n = strlen(str);
	result = compare_memchr(str, c, n);
	comparetestresults("memchr", result, true);
	return (result);
}
