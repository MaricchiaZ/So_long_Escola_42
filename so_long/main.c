/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:21:06 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 13:14:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_sl	game;

	if (check_arguments(argc, argv) == 0)
		return (0);
	if (check_maps (argv, &game) == 0)
	{
		free_matrix_map(&game);
		return (0);
	}
	game.steps = 0;
	game.end_game = 0;
	game_work(&game);
	return (0);
}
