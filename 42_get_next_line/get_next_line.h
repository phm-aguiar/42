/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:17 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/24 19:16:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_node
{
	char			data;
	struct s_node	*next;
}					t_list;

void				insert_char(t_list **head, char character);
void				join(t_list *head, char *line, int counter);
char				*get_next_line(int fd);
void				read_the_buffer(int fd, t_list **head);
void				free_node(t_list **wipe, int counter);
int					ft_lstsize(t_list *lst);
int					ft_strlen(const char *msg);
void				verification_end_line(int bolean, int eof, int fd,
						t_list **head);
void				wipe_all_data(t_list **wipe);

#endif
