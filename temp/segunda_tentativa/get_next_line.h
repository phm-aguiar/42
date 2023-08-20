/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/18 19:33:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}					t_list;

typedef struct s_variables
{
	char			buffer[BUFFER_SIZE + 1];
	size_t			bytesread;
	char			*tmpline;
	t_list			*incomplete_lines;
	char			*end;
}					t_alldata;

char				*ft_strdup(const char *src);
t_list				*ft_lstnew(const char *line);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstdelone(t_list **lst, t_list *node);
void				ft_lstclear(t_list **lst);
char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);

#endif
