/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:43:09 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 17:54:40 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// função que encontra a posição do player
static void	player_position(t_sl *game)
{
	int	l; // coordenadas no mapa
	int	c; // coordenadas no mapa

	l = 0;
	c = 0;
	while (game->map.map[l]) // enquanto houver linha 
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c])  // enquanto houver linha e posição na linha 
		{
			if (game->map.map[l][c] && game->map.map[l][c] == 'P') // se encontrarmos o caracter 'P'
			{
				game->map.pla_pos.x = l; //salvamos a coordenada do P (em matriz de programação a posição é x,y)
				game->map.pla_pos.y = c; //salvamos a coordenada do P
				return ; // já achamos, então saimos dessa função
			}
			c++; // próxima posição
		}
		l++; // próxima linha
	}
}

// função auxiliar que percorre a matriz, simulando o player andando baseada no algoritmo flood fill
// O algoritmo de preenchimento de inundação (flood fill) usa três parâmetros: um ponto inicial, uma cor de destino e uma cor de substituição. No nosso caso o ponto inicial é o 'P', a cor de destino é o caminho que pode-se percorrer '0', e a cor de substituição é a letra que colocamos no caminho para indicar que passamos por ali 'W' 
//(CURIOSIDADE: é o algoritmo do balde de tinta do Paint)
static void	flood_fill(t_sl *game, int px, int py)
{
	if (!game->map.b_map || !game->map.b_map[px]) // se a matriz backup do mapa, ou a linha em questao for nula
		return ; // não temos caminho pra percorrer
	if (game->map.b_map[px][py] == '1' || game->map.b_map[px][py] == 'W') // se for parede ou caminho já percorrido
		return ;  // não temos caminho pra percorrer
	if (game->map.b_map[px][py] == 'C') // se for coletável
		game->vmap.c--; // diminuímos o número dos coletáveis
	if (game->map.b_map[px][py] == 'E') // se for saída
		game->vmap.e--; // diminuímos o número dos coletáveis
	game->map.b_map[px][py] = 'W'; // trocamos o caracter da posição atual por 'W' (walk), isto é, pintamos a posição atual, marcando o caminho já percorrido
	flood_fill(game, px + 1, py); // chamamos essa mesma função recursivamente tentar andar pra direita
	flood_fill(game, px - 1, py); // chamamos essa mesma função recursivamente tentar andar pra esquerda
	flood_fill(game, px, py + 1); // chamamos essa mesma função recursivamente tentar andar pra baixo
	flood_fill(game, px, py - 1);  // chamamos essa mesma função recursivamente tentar andar pra cima
	return ; // fim
}

// função que valida o mapa ao encontrar um caminho possível até a saída, que passe por todos os coletáveis
int	valid_way(t_sl *game)
{
	game->collect = game->vmap.c; //guardamos em game->collect a quantidade de coletáveis
	game->exit = game->vmap.e; //guardamos em game->exit a quantidade de saída
	player_position(game); // encontramos a posição do player
	flood_fill(game, game->map.pla_pos.x, game->map.pla_pos.y); // rodamos o algoritmo de preencimento sobre o backup do mapa, partindo das coordenadas do player
	if (game->vmap.c == 0 && game->vmap.e == 0) // se econtrou todos os coletáveis e a saída
	{
		game->vmap.c = game->collect; //devolvemos para game->collect a quantidade de coletáveis
		game->vmap.e = game->exit; //devolvemos para game->exit a quantidade de saída
		return (1); // uuuuhuuulll!!!! encontramos um caminho válido
	}
	write(1, "Error\ninvalid path\n", 20); // aviso de erro
	return (0); // erro encontrado 
}
