/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 08:37:10 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 17:09:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->pla_pos.x = -1;
	map->pla_pos.y = -1;
	map->map = NULL;
	map->line = 0;
	map->col = 0;
	map->item = 0;
}

void	init_validate_map(t_valmp *vmap)
{
	vmap->c = 0;
	vmap->p = 0;
	vmap->e = 0;
}
