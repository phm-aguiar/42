/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/28 10:54:31 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
// minha função agora extrai e da clear no header até o nó que foi
// tenho que iniciar minha lista e tbm precisa inserir os caracteres nela
// agora aparentemente terminei minha gnl

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
	if (bytes <= 0)
	{
		free_list(list_of_char);
		return ;
	}
	if (*list_of_char == NULL)
		create_empty_list(list_of_char);
	readed[bytes] = '\0';
	split_into_characters(readed, list_of_char);
}

char	*extract_line(t_list **list_of_char, int counter)
{
	char	*line;
	t_list	*current;
	int		index;

	if (counter <= 0)
		return (NULL);
	line = malloc(counter + 2);
	if (line != NULL)
	{
		current = *list_of_char;
		index = 0;
		while (index < counter && current != NULL)
		{
			line[index] = current->data;
			current = current->next;
			index++;
		}
		line[index++] = '\0';
		line[index] = '\n';
		return (line);
	}
	return (NULL);
}

void	remove_nodes(t_list **list_of_char, int counter)
{
	t_list	*current;
	t_list	*temp;

	current = *list_of_char;
	while (counter > 0 && current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		counter--;
	}
	*list_of_char = current;
}

char	*get_next_line(int fd)
{
	static t_list	*list_of_char;
	char			*line;
	int				counter;

	counter = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (list_of_char == NULL || counter == 0)
	{
		read_the_file(fd, &list_of_char);
		counter = ft_size_lst(&list_of_char);
	}
	counter = ft_size_lst(&list_of_char);
	if (counter == 0)
	{
		free_list(&list_of_char);
		return (NULL);
	}
	line = extract_line(&list_of_char, counter);
	if (line != NULL)
	{
		remove_nodes(&list_of_char, counter);
		return (line);
	}
	return (NULL);
}
