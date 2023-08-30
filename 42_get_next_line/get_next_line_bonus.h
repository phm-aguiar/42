/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:48:17 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/30 17:58:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

int					ft_sizelst(t_list **list_of_char);
int					ft_read_error(t_list **main_list, char *current);
void				ft_start_list(t_list **caracter, char c);
void				ft_wipe_list(t_list **list_of_char, int counter);
char				*get_next_line(int fd);
int					ft_read_the_file(int fd, t_list **main_list);
int					ft_split_char(const char *c, t_list **main_list);
void				ft_add_caracter(t_list **main_list, char character);
void				ft_extract_line(t_list **list_of_char, char **line,
						int counter);

#endif
