/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:09:49 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 15:20:12 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_images(t_sl *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	game->image.collect.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/collect.xpm", &x, &y);
	game->image.player.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/player_front.xpm", &x, &y);
	game->image.empty.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/empty.xpm", &x, &y);
	game->image.wall.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/wall.xpm", &x, &y);
	game->image.exit.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/exit_open.xpm", &x, &y);
	if (game->image.collect.img == NULL || game->image.player.img == NULL || \
	game->image.empty.img == NULL || game->image.wall.img == NULL || \
	game->image.exit.img == NULL )
		exit (0);
	return (1);
}

static int	recipe_key(int  keycode, t_sl *game)
{
	
}

static int	recipe_click(t_sl *game)
{
	
}

static int	game_draw(t_sl *game)
{
	
}


void	game_work(t_sl *game)
{
	window(game);
	open_images(game);
	mlx_hook(game->pt_mlx.mlx_window, K_PRESS, K_MASKPRESS, &recipe_key, game);
	mlx_hook(game->pt_mlx.mlx_window, K_PRESS_X, K_MASKPRESS_X, &recipe_click, game);
	mlx_loop_hook(game->pt_mlx.mlx_window, &game_draw, game);
	mlx_loop(game->pt_mlx.mlx);
}
