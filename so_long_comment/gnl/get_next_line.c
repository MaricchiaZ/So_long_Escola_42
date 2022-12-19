/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:51:42 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 14:29:03 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// lemos e o que lemos é armazenado numa string
static char	*read_buffers(int fd, char *store_rest, char *buffer)
{
	int		read_bytes; //número de bytes lidos pela func. read

	read_bytes = 1; // inicia em 1 pra ser verdade o loop abaixo
	while (1) // continua para sempre até que se cumpra alguma das condições (ifs) e saia
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE); //recebe o número de bytes lidos pela func. read, e o caracter lido é armazenado no buffer[0]
		if (read_bytes == -1) // se der erro na leitura
			return (NULL);
		else if (read_bytes == 0) // se acabar a leitura, read não leu mais nenhum byte
			break ;// sai do loop
		buffer[read_bytes] = '\0'; // caso tenha lido, buffer[1] recebe o '\0'
		if (!store_rest) // se a string que armazena a leitura estiver vazia
			store_rest = ft_strdup(""); // inicializamos com a strdup (ela malloca)
		store_rest = ft_strjoin(store_rest, buffer); //  a string que armazena a leitura (store_rest) recebe a junção dela com o novo byte lido
		if (ft_strchr(buffer, '\n')) // se encontrar a quebra de linha
			break ; // sai do loop
	}
	return (store_rest); //retornamos a string com o que foi lido
}

// colocamos um \0 após o \n
static char	*separete_line_rest(char *line)
{
	char	*rest_line; //vai armazenar o que sobrou depois do \n
	int		i; // pra percorrer a string

	i = 0;
	while (line[i] != '\0' && line[i] != '\n') //se n for nem quebra de linha nem fim da string
		i++;// andamos na strinh
	if (line[i] == '\0' || line[1] == '\0') // se tivermos um \n\0
		return (NULL); // já está ok, não tem o que fazer aqui
	rest_line = ft_substr(line, i + 1, ft_strlen(line) - i); //fazemos uma substring do que tiver depois do \n (será guardado na variável estática futuramente)
	if (*rest_line == '\0') // se não tiver resto de linha
	{
		free(rest_line); // free no ponteiro
		rest_line = NULL;
	}
	line[i + 1] = '\0'; //colocamos o \0 após o \n, finalizando a linha aí
	return (rest_line); // retornamos o resto
}

char	*get_next_line(int fd)
{
	char		*line; //guarda a linha lida
	char		*buffer; //cria uma mini string de 2 espaços pra armazenar o byte lido seguido de um \0
	static char	*store_rest; //guarda o resto da leitura pra próxima chamada

	if (fd < 0 || BUFFER_SIZE <= 0) // se fd ou BUFFER_SIZE inválidos...
		return (NULL);
	buffer = (char *) malloc((sizeof(char)) * (BUFFER_SIZE + 1)); // mallocamos o buffer
	if (!buffer) // se o malloc der errado
		return (NULL);
	line = read_buffers(fd, store_rest, buffer); // line recebe a leitura ainda suja, com \n e coisas depois do \n
	free(buffer); // free no ponteiro do buffer
	if (!line) // se a linha estiver vazia
		return (line); // acabou a leitura
	store_rest = separete_line_rest(line); // colocamos uma finalizaçao na linha depois do \n e retornamos o resto
	return (line); // linha pronta
}
