/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/26 11:34:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTES_H
# define TESTES_H
# include "../libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef bool		(*t_estfunction)(void);

typedef struct s_test
{
	const char		*testname;
	t_estfunction	testfunction;
}					t_test;

bool	comparetestresults(const char *functionname,
						int result_original,
						int result_recriada);
bool				test_isalpha(void);
void				runtests(void);
bool				test_isdigit(void);
bool				test_isalnum(void);
bool				test_isascii(void);
bool				test_isprint(void);
bool				test_strlen(void);
bool				test_memset(void);
bool				test_bzero(void);
bool				test_memcpy(void);
bool				test_memmove(void);
bool				test_strlcpy(void);
bool				test_strlcat(void);
bool				test_toupper(void);
bool				test_tolower(void);
bool				test_strchr(void);
bool				test_strrchr(void);
bool				test_strncmp(void);
void				updatebar(int progress, int total);
bool				test_memchr(void);
bool				test_memcmp(void);
bool				test_strnstr(void);
bool				test_atoi(void);

typedef bool		(*t_estfunction)(void);

extern const t_test	g_tests[];

#endif
