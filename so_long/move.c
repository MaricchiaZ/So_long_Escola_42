/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:49:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 12:19:38 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_be_ok(t_sl *game, int keycode, int line, int col)
{
	if (game->map.map[line][col] == '1')
		return (0);
	if (game->map.map[line][col] == 'E' && game->vmap.c == 0)
		game->end_game = 1;
	if (game->map.map[line][col] == 'E')
		return (0);
	if (game->end_game)
		return (0);
	if (keycode == W || keycode == S || keycode == A || keycode == D || \
	keycode == AW_UP || keycode == AW_DN || keycode == AW_L || \
	keycode == AW_R)
		return (1);
	return (0);
}

void	move_player(t_sl *game, int keycode, int col, int line)
{
	char	*temp;
	int		px;
	int		py;
	int		move_ok;

	px = game->map.pla_pos.x;
	py = game->map.pla_pos.y;
	move_ok = move_be_ok(game, keycode, line, col);
	if (move_ok > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->vmap.c--;
		game->map.map[px][py] = '0';
		game->map.map[line][col] = 'P';
		game->map.pla_pos.y = col;
		game->map.pla_pos.x = line;
		game->steps++;
		temp = ft_itoa(game->steps);
		ft_putstr("Steps move: ");
		ft_putstr(temp);
		ft_putstr("\n");
		free(temp);
	}
}
