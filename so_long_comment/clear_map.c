/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:47:28 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 15:55:14 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// função que dá free nos ponteiros internos da matriz map map.map[i] para então dar free  no ponteiro de ponteiro map.map - EVITA LEAKS 
void	free_matrix_map(t_sl *game)
{
	int	i;

	i = 0;
	if (game->map.map == NULL) // se a matriz não for nula
		return ;
	while (game->map.map[i] && game->map.b_map[i]) // enquanto tiver ponteiro não NULL no map e no backup do map
	{
		free(game->map.map[i]); // free nos ponteiros
		free(game->map.b_map[i]); // free nos ponteiros
		i++;
	}
	free(game->map.map); // free nos ponteiros de ponteiros
	free(game->map.b_map); // free nos ponteiros de ponteiros
}
