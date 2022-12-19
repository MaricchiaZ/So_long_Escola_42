/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:47:28 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 11:35:31 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matriz_map(t_sl *game)
{
	int	i;

	i = 0;
	if (game->map.map == NULL)
		return ;
	while (game->map.map[i] && game->map.b_map[i])
	{
		free(game->map.map[i]);
		free(game->map.b_map[i]);
		i++;
	}
	free(game->map.map);
	free(game->map.b_map);
}
