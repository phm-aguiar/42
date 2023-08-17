/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:36:20 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/25 18:48:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

const t_test	g_tests[] = {
{"test_isalpha", test_isalpha},
{"test_isdigit", test_isdigit},
{"test_isalnum", test_isalnum},
{"test_isascii", test_isascii},
{"test_isprint", test_isprint},
{"test_tolower", test_tolower},
{"test_toupper", test_toupper},
{"test_strlen", test_strlen},
{"test_atoi", test_atoi},
{"test_memcpy", test_memcpy},
{"test_memcmp", test_memcmp},
{"test_memcmp", test_memmove},
{"test_memchr", test_memchr},
};

void	runtests(void)
{
	bool	alltestspassed;
	int		totaltests;
	int		testscompleted;
	int		counter;

	alltestspassed = true;
	totaltests = sizeof(g_tests) / sizeof(g_tests[0]);
	testscompleted = 0;
	counter = 0;
	while (counter < totaltests)
	{
		updatebar(++testscompleted, totaltests);
		alltestspassed &= g_tests[counter].testfunction();
		counter++;
	}
	if (alltestspassed)
	{
		printf("Todos os testes comparativos passaram.\n");
	}
	else
	{
		printf("Alguns testes comparativos falharam.\n");
	}
}
