/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:21:06 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 16:37:28 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// é aqui que sua jornada inicia-se
int	main(int argc, char *argv[])
{
	t_sl	game; // declaramos o uso da struct game

	if (check_arguments(argc, argv) == 0) // se der erro na checagem dos argumentos
		return (0); //erro encontrado, para a execução aqui
	if (check_maps (argv, &game) == 0) // se der erro na checagem do mapa
	{
		free_matrix_map(&game); //liberamos os ponteiros do mapa
		return (0); //erro encontrado, para a execução aqui
	}
	game.steps = 0; // passos andados inicia-se zerado
	game.end_game = 0; // possibilidade de finalizar o jogo é zero (e se mantém assim até se coletar tudo e chegar na saída)
	game_work(&game); // função que orquestra o jogo
	return (0); // fim de tudo
}
