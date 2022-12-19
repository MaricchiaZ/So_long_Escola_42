/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:01:32 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 17:28:17 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//função que splita a string map, tranformando-a em uma matriz, com cada ponteiro apontando para uma linha 
static char	**make_map(char *map, int ck_line)
{
	char	**temp;

	temp = NULL;
	if (ck_line >= 3)
		temp = ft_split(map, '\n');
	free(map);
	return (temp);
}

// função que lê o mapa passado por argumento e cria uma uma matriz, com cada ponteiro apontando para uma linha 
char	**read_maps(char **argv)
{
	int		fd; // descritor de arquivo pra func read
	int		ck_line; // checa se a linha tem pelo menos 3 caracteres (menor linha válida possível)
	char	*gnl_line; // string que recebe a linha lida pela gnl
	char	*map; // string com o mapa, vai sendo formada a medida que a gnl lê as linhas do fd

	fd = open (argv[1], O_RDONLY); // abrimos o arquivo em um fd
	if (fd < 0) // se a função open falhar e o fd for inválido
		return (NULL); // não temos mapa
	gnl_line = get_next_line(fd); // gnl_line recebe a primeira linha do mapa
	map = ft_strdup(""); // mapa é inicializado zerado
	ck_line = ft_strlen(gnl_line); // checkline recebe o comprimento da linha 
	while (gnl_line) // enquanto algo retornar da função gnl
	{
		map = ft_strjoin(map, gnl_line); //map recebe a linha lida
		free (gnl_line); // limpamos a strig temporária da linha lida
		gnl_line = get_next_line(fd); // lemos mais uma linha 
		if ((ck_line < 3 && gnl_line != NULL) || gnl_line == NULL ) // se o tamanho da linha for menor que 3 e algo for lido OU nada foi lido
			continue ; // continua-se 
		ck_line = ft_strlen(gnl_line); // recebemos o tamanho da linha lida
	}
	close(fd); // fechamos o fd
	return (make_map(map, ck_line)); // retornamos o mapa splitado
}
