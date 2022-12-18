/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:38:53 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 16:20:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window(t_sl *game)
{
	game->w_width = IMG_SIZE * (game->map.col + 1);
	game->w_heigth = IMG_SIZE * (game->map.line + 1);
	printf("game->w_width: %i, game->w_heigth: %i\n\n", game->w_width, game->w_heigth );
	game->pt_mlx.mlx = mlx_init();
	if (game->pt_mlx.mlx == NULL)
		return (0);
	game->pt_mlx.mlx_window = mlx_new_window(game->pt_mlx.mlx, game->w_width, game->w_heigth, "so_long - maclara-");
	if (game->pt_mlx.mlx_window == NULL )
		return (0);
	return (1);
}
