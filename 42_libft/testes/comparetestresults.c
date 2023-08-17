/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparetestresults.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:13:48 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/24 19:14:41 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testes.h"

bool	comparetestresults(const char *functionname, int result_original,
		int result_recriada)
{
	if (result_original == result_recriada)
	{
		printf("\033[32mTeste para %s bem-sucedido.\033[0m\n", functionname);
		usleep(500000);
		return (true);
	}
	else
	{
		printf("\033[31mTeste para %s falhou. Resultado original: %d,Resultado recriado: \
		%d\033[0m\n", functionname, result_original, result_recriada);
		usleep(500000);
		return (false);
	}
}
