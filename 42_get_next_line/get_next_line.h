/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:47:41 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/21 18:04:20 by phenriq2         ###   ########.fr       */
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
	char			*data;
	struct s_node	*next;
}					t_list;

typedef struct s_gnlvariables
{
	int				bytesread;
	char			*line;
	char			*buffer;
}					t_gnl;

char				*get_next_line(int fd);
void				read_and_stash(t_list **head, int *ptr_bytes, int fd);
void				add_to_head(t_list **head, char *buff, int ptr_bytes);
void				extract_line(t_list *head, char **line);
void				clean_head(t_list **head);
int					ft_strlen(char *str);
void				free_head(t_list *head);
int					found_newline(t_list *head);
void				generate_line(char **line, t_list *head);
t_list				*ft_lst_get_last(t_list *head);

#endif