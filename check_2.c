/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:27:16 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 15:18:07 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	square_map(t_sl *game)
{
	int	l;

	l = 0;
	game->map.col = ft_strlen(game->map.map[0]);
	while(game->map.map[l] && (game->map.col == ft_strlen(game->map.map[l])))
		l++;
	if (game->map.map[l] == NULL)
	{
		game->map.col--;
		game->map.line = l - 1;
		return (1);        
	}
	write(1, "Error\nmap is not square", 24);
	return (0);
}

static int	check_vertical_wall(t_sl *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		y++;
	if(y - 1 != game->map.line)
	{
		write(1, "Error\nvertical left wall map is broken", 39);
		return (0);
	}
	x = game->map.col;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		y++;
	if(y - 1 != game->map.line)
	{
		write(1, "Error\nvertical rigth wall map is broken", 40);
		return (0);
	}    
	return (1);
}

static int	check_horizontal_wall(t_sl *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		x++;
	if(x - 1 != game->map.col)
	{
		write(1, "Error\nhorizontal top wall map is broken", 40);
		return (0);
	}
	x = 0;
	y = game->map.line;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		x++;
	if(x - 1 != game->map.col)
	{
		write(1, "Error\nhorizontal bottom wall map is broken", 43);
		return (0);
	}    
	return (1);
}

int	check_wall(t_sl *game)
{
	if(check_vertical_wall(game) == 0)
		return (0);
	if(check_horizontal_wall(game) == 0)
		return (0);
	return (1);
}
