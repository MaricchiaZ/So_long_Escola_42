/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:03:30 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 15:52:12 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// confere o número de argumentos passado e se o argumento passado termina em .ber (extensão exigida para o mapa)
int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2) // se tiver 2 argumentos (a.out + 1)
	{
		i = ft_strlen(argv[1]); // mede o tam do segundo argumento (possivelmente o mapa)
		if ((argv[1][i - 4] == '.') && (argv[1][i - 3] == 'b') && \
		(argv[1][i - 2] == 'e') && (argv[1][i - 1] == 'r')) // confere se termina com .ber
			return (1); // se estiver ok
		else // em caso de erro, de não ser .ber
		{
			write (1, "Error\nInvalid file format!\n", 28); // reporta o erro
			return (0); // 0 ou falso, checagem encontrou erro
		}
	}
	write (1, "Error\nInvalid argument number!\n", 32); // se forem passados argumentos em número diferente de 2
	return (0); // 0 ou falso, checagem encontrou erro
}

// coloca a mensagem pertinente ao encontrar erro na quantidade de ítens do mapa
static int	msg_error_itens(t_sl *game)
{
	if (game->vmap.e != 1 || game->vmap.p != 1 || game->vmap.c == 0) // se tiver erro em alguma quantidade de ítens do mapa
	{
		if (game->vmap.e != 1) // número de saídas diferente de 1
		{
			write(1, "Error\ninvalid number of exit in map\n", 37);
			return (0); // erro encontrado
		}
		if (game->vmap.p != 1) // número deplayers diferente de 1
		{
			write(1, "Error\ninvalid number of player in map\n", 39);
			return (0); // erro encontrado
		}
		if (game->vmap.c == 0) // não ter nenhum coletável
		{
			write(1, "Error\ninvalid number of collectable on map\n", 44);
			return (0); // erro encontrado
		}
	}
	return (1); // se não tiver nenhum erro
}

// confere se os caracteres do mapa são válidos
static int	validate_caracters_map(t_sl *game)
{
	int	l; //pra percorrer as linhas na matriz mapa (game->map.map)
	int	c; //pra percorrer as colunas na matriz mapa (game->map.map)

	c = 0;
	l = 0;
	while (game->map.map[l]) // enquanto tiver linhas pra percorrer
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c]) // dentro dessa linha l, enquanto tiver colunas
		{
			if (game->map.map[l][c] && (game->map.map[l][c] != 'P' && \
			game->map.map[l][c] != 'C' && game->map.map[l][c] != 'E' && \
			game->map.map[l][c] != '0' && game->map.map[l][c] != '1')) // se for diferente de P-player ou C-coletável ou E-saída ou O-andável ou 1-muro
			{
				write(1, "Error\nCaracter invalid in map\n", 31); // um caracter estranho foi achado
				return (0); // erro encontrado
			}
			c++;
		}
		l++;
	}
	return (1); // tudo ok com os caracteres do mapa são válidos
}

// confere se a quantidada de ítens do mapa está válida
static int	validate_itens_map(t_sl *game)
{
	int	l; //pra percorrer as linhas na matriz mapa (game->map.map)
	int	c; //pra percorrer as colunas na matriz mapa (game->map.map)

	l = 0;
	c = 0;
	while (game->map.map[l]) // enquanto tiver linhas pra percorrer
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c]) // dentro dessa linha l, enquanto tiver colunas
		{
			if (game->map.map[l][c] && game->map.map[l][c] == 'P') // se for player
				game->vmap.p++; // guarda nessa variável
			if (game->map.map[l][c] && game->map.map[l][c] == 'C') // se for coletável
				game->vmap.c++; // guarda nessa variável
			if (game->map.map[l][c] && game->map.map[l][c] == 'E') // se for saída
				game->vmap.e++; // guarda nessa variável
			c++;
		}
		l++;
	}
	return (msg_error_itens(game)); //retorna mensagem adequada em caso de erro, ou 1 se tiver tudo ok
}

// checa se o mapa é legivel, se é quadrado, 
int	check_maps(char **argv, t_sl *game)
{
	game->map.map = read_maps(argv); // armazena o mapa lido na matriz map
	if (game->map.map == NULL) // se a matriz estievr vazia
	{
		write (1, "Error\nmap error\n", 16); // mapa com erro
		return (0); // erro encontrado
	}
	game->map.b_map = read_maps(argv); // salvamos um backup do mapa para usar na conferência de caminho válido (algoritmo flood fill pinta o mapa)
	if (game->map.b_map == NULL) // se o backup deu erro
	{
		write (1, "Error\nmap error\n", 16); // mapa com erro
		return (0);
	}
	init_validate_map(&game->vmap); // iniciamos a struct vmap
	if (validate_caracters_map(game) == 0) // se econtrarmos algum caracter inválido no mapa
		return (0); // checagem encontrou um erro
	if (validate_itens_map(game) == 0) // se a quantidade de ítens do mapa tiver erro
		return (0); // checagem encontrou um erro
	if (square_map(game) == 0) // se o mapa nao for quadrado
		return (0); // checagem encontrou um erro
	if (check_wall(game) == 0) // se alguma parede externa estiver incompleta
		return (0); // checagem encontrou um erro
	if (valid_way(game) == 0) // se não existit um caminho possível, isto é, o mapa não for válido
		return (0); // checagem encontrou um erro
	return (1); // // checagem ok
}
