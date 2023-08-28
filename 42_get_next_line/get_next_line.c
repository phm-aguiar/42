/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:20:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/28 17:08:29 by phenriq2         ###   ########.fr       */
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
// minha função agora extrai e da clear no caracterer até o nó que foi
// tenho que iniciar minha lista e tbm precisa inserir os caracteres nela
// agora aparentemente terminei minha gnl

/*
Definir a Estrutura da Lista Encadeada Estática (StaticLinkedList):
Crie uma estrutura para representar a lista encadeada estática que será usada para armazenar os caracteres de uma linha do arquivo.
Parâmetros: Um array de caracteres,
	um índice do próximo elemento e o tamanho máximo da lista.
Definir a Função (read_line_from_fd):

Defina a função que lerá uma linha do descritor de arquivo usando a lista encadeada estática e um tamanho de buffer variável.
Parâmetros: Descritor de arquivo (fd).
Inicializar a Lista Encadeada Estática (initialize_list):

Crie uma instância da lista encadeada estática,
	inicializando o array de caracteres,
o índice do próximo elemento e definindo o tamanho máximo da lista.
Parâmetros: Nenhum.
Ler Caracteres do Descritor de Arquivo em Buffer (read_characters_to_buffer):

Use um loop para ler caracteres do arquivo associado ao descritor de arquivo em um buffer de tamanho variável.
À medida que lê caracteres,
	verifique se atingiu o final de linha (\n) ou o final do arquivo.
Se não atingiu o final de linha ou o final do arquivo,
	adicione os caracteres ao buffer da lista encadeada estática.
Parâmetros: A lista encadeada estática,
	o descritor de arquivo e o tamanho máximo do buffer.
Retornar a Linha (return_line):

Converta os caracteres armazenados na lista encadeada estática em uma string e retorne a linha lida
do arquivo como resultado da função.
Parâmetros: A lista encadeada estática.
Tratamento de Erros (error_handling):

Implemente tratamento de erros para lidar com problemas ao ler do descritor de arquivo,
	como erros de leitura ou fim de arquivo.
Parâmetros: Mensagens de erro ou exceções, se houverem.
Finalizar a Função (finalize_function):

Finalize a função,
	garantindo que a string contendo a linha tenha sido retornada e a lista encadeada estática tenha sido liberada.
Parâmetros: Nenhum.
Este é o fluxo geral para a criação da função read_line_from_fd que lê uma linha do arquivo usando uma lista encadeada estática
e um tamanho de buffer variável.
Certifique-se de implementar cada passo com cuidado,
	considerando situações de erro e lidando adequadamente com o final do arquivo.
A função deve retornar uma única linha do arquivo associado ao descritor de arquivo fornecido como entrada.
*/

void	extract_line(t_list **list_of_char, char **line)
{
	t_list	*current;
	int		index;

	if (line != NULL)
	{
		current = *list_of_char;
		index = 0;
		while (current->data != '\n' && current != NULL)
		{
			*line[index] = current->data;
			current = current->next;
			index++;
		}
		*line[index++] = '\0';
		*line[index] = '\n';
		return ;
	}
	return ;
}

void	add_caracter(t_list **caracter, int c, char *buffer, int fd)
{
	t_list	*new_node;
	t_list	*current;

	while (*buffer)
	{
		if (caracter == NULL || *caracter == NULL)
			return ;
		new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node == NULL)
			return ;
		new_node->data = *buffer;
		new_node->next = NULL;
		current = *caracter;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		buffer++;
	}
	if (c)
		read_the_file(fd, caracter);
}

void	read_the_file(int fd, t_list **caracter)
{
	char	current[BUFFER_SIZE + 1];
	int		bytesread;
	int		bol;
	int		index;

	bol = 0;
	index = 0;
	bytesread = read(fd, current, BUFFER_SIZE);
	while (current[index])
	{
		if (current[index] == '\0' || current[index] == '\n')
			bol = 1;
		index++;
	}
	current[bytesread] = '\0';
	add_caracter(caracter, bol, current, fd);
}

char	*get_next_line(int fd)
{
	static t_list	*caracter;
	char			*line;
	int				counter;

	counter = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (caracter == NULL)
		start_list(&caracter);
	read_the_file(fd, &caracter);
	if (!caracter)
		return (NULL);
	counter = ftsizelst(&caracter) + 1;
	line = malloc(counter);
	if (!line)
	{
		wipe(&caracter, ftsizelst(&caracter));
		return (NULL);
	}
	extract_line(&caracter, &line);
	if (!line)
		return (NULL);
	wipe(&caracter, ftsizelst(&caracter));
	return (line);
}
