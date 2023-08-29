/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:17 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/29 15:32:05 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_node
{
	char			data;
	struct s_node	*next;
}					t_list;

int					read_the_file(int fd, t_list **caracter);
char				*get_next_line(int fd);
void				add_caracter(t_list **caracter, char c);
void				start_list(t_list **caracter, char c);
int					ftsizelst(t_list **list_of_char);
void				wipe_all(t_list **list_of_char);
void				wipe(t_list **list_of_char, int counter);

#endif
