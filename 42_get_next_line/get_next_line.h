/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:54 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/17 16:38:49 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_itoa
{
	int				counter;
	char			*memory;
}					t_data;
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
size_t				ft_strlen(const char *msg);
t_list				*ft_lstnew(char *content);
void				ft_lstdelone(t_list *lst, void (*ft_del)(void *));
void				ft_lstclear(t_list **lst, void (*ft_del)(void *));
void				ft_del(void *content);

#endif
