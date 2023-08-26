/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/25 20:58:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// vamos começar criando o cabeçalho
// depois vamos retornar a saida
// sabemos que a saida desse codigo é uma linha ... no caso uma string...
// agora que temos a saida ... vamos para a parte da variavel estatica
// nela vamos colocar uma lista encadeada
// agora que temos isso vamos começar a ler o arquivo
// criei uma string valida adicionando raba 0 no final
// com tudo o que foi feito eu preciso tratar a minha string
// tendo uma função que separa meu buffer em caracteres fica facil entender
// agora que tenho uma função que coloca todos os caracteres na minha lista
// tenho que fazer uma função que retorna uma string
// minha função agora extrai

int	ft_size_lst(t_list **list_of_char)
{
	t_list	*size;
	int		counter;

	size = *list_of_char;
	counter = 0;
	while (size != NULL && size->data != '\n')
	{
		counter++;
		size = size->next;
	}
	return (counter);
}

char	*extract_and_remove_until_newline(t_list **list_of_char)
{
	t_list	*current;
	int		counter;
	char	*line;
	t_list	*temp;

	counter = ft_size_lst(list_of_char);
	line = malloc(counter + 2);
	if (line != NULL)
	{
		current = *list_of_char;
		counter = 0;
		while (counter > 0 && current != NULL)
		{
			line[counter - 1] = current->data;
			temp = current;
			current = current->next;
			free(temp);
			counter--;
		}
		line[counter++] = '\0';
		line[counter] = '\n';
		*list_of_char = current;
		return (line);
	}
	return (NULL);
}

void	split_into_characters(const char *readed, t_list **list_of_char)
{
	while (*readed)
	{
		insert_into_list(list_of_char, *readed);
		readed++;
	}
}

void	read_the_file(int fd, t_list **list_of_char)
{
	char	readed[BUFFER_SIZE + 1];
	int		bytes;

	bytes = read(fd, readed, BUFFER_SIZE);
	readed[bytes] = '\0';
	split_into_characters(readed, list_of_char);
}

char	*get_next_line(int fd)
{
	static t_list	*list_of_char;
	char			*line;

	line = extract_and_remove_until_newline(&list_of_char);
	return (line);
}
