/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:47:41 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/20 15:04:56 by phenriq2         ###   ########.fr       */
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
}					t_node;

typedef struct s_gnlvariables
{
	size_t			bytesread;
	char			*line;
	char			*buffer;
}					t_gnl;

t_node				*ft_lstnew(const char *s);
char				*get_next_line(int fd);
#endif