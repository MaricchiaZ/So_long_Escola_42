/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:38:53 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 13:16:51 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window(t_sl *game)
{
	game->w_width = IMG_SIZE * (game->map.col + 1);
	game->w_heigth = IMG_SIZE * (game->map.line + 1);
	game->pt_mlx.mlx = mlx_init();
	if (game->pt_mlx.mlx == NULL)
	{
		free_matrix_map(game);
		return (0);
	}
	game->pt_mlx.mlx_window = mlx_new_window(game->pt_mlx.mlx, game->w_width, \
	game->w_heigth, "so_long - maclara-");
	if (game->pt_mlx.mlx_window == NULL )
		return (0);
	return (1);
}

int	destroyer_window(t_sl *game)
{
	free_matrix_map(game);
	if (!game->pt_mlx.mlx)
		exit (0);
	mlx_clear_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window);
	mlx_loop_end(game->pt_mlx.mlx);
	if (game->image.collect.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.collect.img);
	if (game->image.empty.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.empty.img);
	if (game->image.player.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.player.img);
	if (game->image.wall.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.wall.img);
	if (game->image.exit.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.exit.img);
	mlx_destroy_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window);
	mlx_destroy_display(game->pt_mlx.mlx);
	free(game->pt_mlx.mlx);
	exit (0);
	return (0);
}
