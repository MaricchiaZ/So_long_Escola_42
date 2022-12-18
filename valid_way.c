/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:43:09 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 11:04:47 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    player_position(t_sl *game)
{
    int l;
    int c;
    
    while(&game->map && game->map.map[l] && game->map.map[l][c])
    {
        l = 0;
        while(&game->map && game->map.map[l] && game->map.map[l][c])
        {
            c = 0;
            if(game->map.map[l][c] && game->map.map[l][c] == 'P')
            {
                game->map.pla_pos.x = c;
                game->map.pla_pos.y = l;
                return ;
            }
            c++;
        }
        l++;
    }
}

int valid_way(t_sl *game)
{
    game->collect = game->vmap.c; //pega os valores já contabilizados na func validate_itens_map
    game->exit = game->vmap.e; //pega os valores já contabilizados na func validate_itens_map
    
    
}
