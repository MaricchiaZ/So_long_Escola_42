/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:03:30 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 10:39:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		if ((argv[1][i - 4] == '.') && (argv[1][i - 3] == 'b') && \
		(argv[1][i - 2] == 'e') && (argv[1][i - 1] == 'r'))
			return (1);
		else
		{
			write (1, "Error\nInvalid file format!\n", 28);    
			return (0);  
		}

	}
	write (1, "Error\nInvalid argument number!\n", 32);
	return (0);
}

static void	msg_error_itens(t_sl *game)
{
	if (game->vmap.e != 1)
	{
		write(1, "Error\ninvalid number of exit in map", 36);
		return ;     
	}
	if (game->vmap.p != 1 )
	{
		write(1, "Error\ninvalid number of player in map", 38);
		return ;
	}
	if (game->vmap.c == 0)
	{
		write(1, "Error\ninvalid number of collectable on map", 43);
		return ;
	}
}

static int	validate_caracters_map(t_sl *game)
{
	int	l;
	int	c;
	
	c = 0;
	l = 0;
	while (game->map.map[l])
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c])
		{
			if (game->map.map[l][c] && (game->map.map[l][c] != 'P' && \
			game->map.map[l][c] != 'C' && game->map.map[l][c] != 'E' && \
			game->map.map[l][c] != '0' && game->map.map[l][c] != '1'))
			{
				write(1,"Error\nCaracter invalid in map", 30);
				return (0);
			}
			c++;
		}
		l++;
	}
	return (1);
}

static int	validate_itens_map(t_sl *game)
{
	int	l;
	int	c;
	
	l = 0;
	c = 0;
	while(game->map.map[l])
	{
		c = 0;
		while(game->map.map[l] && game->map.map[l][c])
		{
			if(game->map.map[l][c] && game->map.map[l][c] == 'P')
				game->vmap.p++;
			if(game->map.map[l][c] && game->map.map[l][c] == 'C')
				game->vmap.c++;
			if(game->map.map[l][c] && game->map.map[l][c] == 'E')
				game->vmap.e++;
			c++;
		}
		l++;
	}
	if (game->vmap.e != 1 || game->vmap.p != 1 || game->vmap.c == 0)
	{
		msg_error_itens(game);
		return (0);
	}
	return (1);
}

int	check_maps(char **argv, t_sl *game)
{
	game->map.map = read_maps(argv);
	if (game->map.map == NULL)
	{
		write (1, "Error\nmap error\n", 17);
		return (0);
	}
	game->map.b_map = read_maps(argv);
	if (game->map.b_map == NULL)
	{
		write (1, "Error\nmap error 2\n", 17);
		return (0);
	}
	init_validate_map(&game->vmap);
	if(validate_caracters_map(game) == 0)
		return (0);
	if(validate_itens_map(game) == 0)
		return (0);
	if(square_map(game) == 0)
		return (0);
	if (check_wall(game) == 0)
		return (0);
	if (valid_way(game) == 0)
		return (0);
	return (1);
}
