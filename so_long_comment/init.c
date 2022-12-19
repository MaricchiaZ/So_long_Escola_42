/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 08:37:10 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 15:49:29 by maclara-         ###   ########.fr       */
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

 // inicialização da struct vmap que validará a quantidade de ítens do mapa
void	init_validate_map(t_valmp *vmap)
{
	vmap->c = 0; // coletáveis
	vmap->p = 0; // player
	vmap->e = 0; // saída
}
