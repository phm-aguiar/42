/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/18 12:13:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}					t_list;

typedef struct s_variables
{
	ssize_t			bytesread;
	char			*newline;
	char			*line;
	t_list			*temp;
	char			*new_string;
	size_t			counter;
	size_t			index;
	t_list			*complete_line;
	char			*line2;
}					t_alldata;

char				*ft_strdup(const char *src);
t_list				*ft_lstnew(const char *line);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstdelone(t_list **lst, t_list *node);
void				ft_lstclear(t_list **lst);
char				*get_next_line(int fd);

#endif
