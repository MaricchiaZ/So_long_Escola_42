/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:27:16 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 14:56:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// confere se o mapa é retangular, isto é, se todas as linhas tem o mesmo comprimento
int	square_map(t_sl *game)
{
	int	l; //índice para andar de uma linha para a outra na matriz game->map

	l = 0;
	game->map.col = ft_strlen(game->map.map[0]); // guardamos o tamanho da primeira linha
	while (game->map.map[l] && (game->map.col == ft_strlen(game->map.map[l]))) // enquanto a linha observada tiver o mesmo tamanho da linha inicial
		l++; // olhamos de linha em linha
	if (game->map.map[l] == NULL) // se todas forem iguais chegaremos no ponteiro NULL no fim da tabela
	{
		game->map.col--; // sabemos que a numeração de coluna vai até strlen -1, por conta de se iniciar no 0
		game->map.line = l - 1; // sabemos que a numeração das linhas vai até l -1, por conta de se iniciar no 0
		return (1); // retornamos ok - o mapa é retangular então podemos trabalhar com ele
	}
	write(1, "Error\nmap is not square\n", 25); // caso o mapa tenha alguma linha incompleta
	return (0); // retornamos erro
}

// checa se as laterais verticais do mapa são formadas por 1 ou parede
static int	check_vertical_wall(t_sl *game) 
{
	int	x; // pra percorrer a matriz
	int	y; // pra percorrer a matriz

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1') // primeira coluna do mapa
		y++;
	if (y - 1 != game->map.line) // se o número de y for menor do que o tam da coluna
	{
		write(1, "Error\nvertical left wall map is broken\n", 40); // falta alguma parte da parede
		return (0); // deu erro
	}
	x = game->map.col; // ultima coluna do mapa
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		y++;
	if (y - 1 != game->map.line) // se o número de y for menor do que o tam da coluna
	{
		write(1, "Error\nvertical rigth wall map is broken\n", 41);// falta alguma parte da parede
		return (0); // deu erro
	}
	return (1); // deu certo, não há falhas na parede
}

// checa se as laterais de cima e de baixo do mapa são formadas por 1 ou parede
static int	check_horizontal_wall(t_sl *game)
{
	int	x; // pra percorrer a matriz
	int	y; // pra percorrer a matriz

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1') // parte de cima
		x++;
	if (x - 1 != game->map.col) // se o número de y for menor do que o tam da coluna
	{
		write(1, "Error\nhorizontal top wall map is broken\n", 41); // falta alguma parte da parede
		return (0); // erro na parede
	}
	x = 0;
	y = game->map.line; //ultima linha do mapa
	while (game->map.map[y] && game->map.map[y][x] == '1') // parte de baixo
		x++;
	if (x - 1 != game->map.col) // se o número de y for menor do que o tam da coluna
	{
		write(1, "Error\nhorizontal bottom wall map is broken\n", 44); // falta alguma parte da parede
		return (0); // erro na parede
	}
	return (1); // parede ok
}

// confere se o mapa todo é cercado de 1, e retorna 1=OK ou 0=Broken
int	check_wall(t_sl *game)
{
	if (check_vertical_wall(game) == 0) // se as laterais tem erro...
		return (0); // ... reporta o erro
	if (check_horizontal_wall(game) == 0) // se em cima ou baixo tem erro...
		return (0); // ... reporta o erro
	return (1); // se está tudo ok... retorna 1/true
}
