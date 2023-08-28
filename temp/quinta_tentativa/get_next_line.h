/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:17 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/27 19:58:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
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

void				insert_into_list(t_list **head, char character);
int					ft_size_lst(t_list **list_of_char);
void				split_into_characters(const char *readed,
						t_list **list_of_char);
void				read_the_file(int fd, t_list **list_of_char);
char				*extract_line(t_list **list_of_char, int counter);
void				remove_nodes(t_list **list_of_char, int counter);
char				*get_next_line(int fd);
void				create_empty_list(t_list **current);
void				free_list(t_list **head);

#endif
