/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:09:49 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 12:28:31 by maclara-         ###   ########.fr       */
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
	game->image.player.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/player.xpm", &x, &y);
	game->image.empty.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/empty.xpm", &x, &y);
	game->image.wall.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/wall.xpm", &x, &y);
	game->image.exit.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, "./imgs/exit.xpm", &x, &y);
	if (game->image.collect.img == NULL || game->image.player.img == NULL || \
	game->image.empty.img == NULL || game->image.wall.img == NULL || \
	game->image.exit.img == NULL )
		destroyer_window(game);
	return (1);
}

static int	recipe_key(int  keycode, t_sl *game)
{
	int	line;
	int	col;
	
	line = game->map.pla_pos.x; // salvamos a posição atual do player
	col = game->map.pla_pos.y; // salvamos a posição atual do player
	// conferimos a tecla apertada e agimos
	if (keycode == ESC)
		destroyer_window(game);
	if (keycode == W || keycode == AW_UP)
		line--;
	if (keycode == S || keycode == AW_DN)
		line++;
	if (keycode == A || keycode == AW_L)
		col--;
	if (keycode == D || keycode == AW_R)
		col++;
	if (!game->end_game) // se o end_game ainda for 0, isto é ainda não coletou tudo...
	{
		move_player(game, keycode, col, line); // movemos o player
	}
	return (1);
}

static void	put_one_image(t_sl *game, int line, int col)
{
	if (game->map.map[line] && game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, game->image.wall.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, game->image.empty.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == 'P')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, game->image.player.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == 'C')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, game->image.collect.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == 'E')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, game->image.exit.img, IMG_SIZE * col, IMG_SIZE * line);
}

static int	game_draw(t_sl *game)
{
	int	line;
	int	col;
	
	line = 0;
	while (line <= game->map.line)
	{
		col = 0;
		while (col <= game->map.col)
		{
			put_one_image(game, line, col);
			col++;
		}
		line++;
	}
	return (0);
}

void	game_work(t_sl *game)
{
	window(game);
	open_images(game);
	mlx_hook(game->pt_mlx.mlx_window, K_PRESS, 1L<<0, &recipe_key, game);
	mlx_hook(game->pt_mlx.mlx_window, K_PRESS_X, 1L<<2, &destroyer_window, game);
	mlx_loop_hook(game->pt_mlx.mlx, &game_draw, game);
	mlx_loop(game->pt_mlx.mlx);
}
