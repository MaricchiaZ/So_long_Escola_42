/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:43:09 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 15:12:36 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    player_position(t_sl *game)
{
    int l;
    int c;
    
    l = 0;
    c = 0;
    while (game->map.map[l])
    {
        c = 0;
        while (game->map.map[l] && game->map.map[l][c])
        {
            if (game->map.map[l][c] && game->map.map[l][c] == 'P')
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
// Flood fill é um algoritmo de preenchimento, sendo possível andar, ele preenche com algo.
static void    flood_fill(t_sl *game, int  px, int py) 
{
    if (game->map.b_map[px][py] == '1' || game->map.b_map[px][py] == 'W') //se for muro ou um caminho já percorrido, retornamos
        return ;
    if (game->map.b_map[px][py] == 'C') // se for um coletável
        game->vmap.c--; // ele diminui os coletáveis 'á coletar'
    if (game->map.b_map[px][py] == 'E') // se ele achar a saída
        game->vmap.e--; // ele ele diminui a saída 'á encontrar'
    game->map.b_map[px][py] = 'W'; // marca como W (walk) o caminho já percorrido
    flood_fill(game, px + 1, py); //tenta andar pra direita - recursivamente
    flood_fill(game, px - 1, py); // tenta andar para a esquerda - recursivamente 
    flood_fill(game, px, py + 1); // tenta andar para baixo - recursivamente
    flood_fill(game, px, py - 1); // tenta andar para cima - recursivamente
    return ;
}

int valid_way(t_sl *game)
{
    game->collect = game->vmap.c; //pega os valores já contabilizados na func. validate_itens_map
    game->exit = game->vmap.e; //pega os valores já contabilizados na func. validate_itens_map
    player_position(game); // acha a posição do player e salva na struct
    flood_fill(game, game->map.pla_pos.x, game->map.pla_pos.y ); //testa os possíveis caminhos
    if (game->vmap.c == 0 && game->vmap.e == 0) //se coletou todos os coletáveis e achou a saída, é um mapa válido
    {
        game->vmap.c = game->collect; // devolvemos o valor pra variável // possível retirar
        game->vmap.e = game->exit; // devolvemos o valor pra variável //  possivel rerirar
        return (1); // td ok
    }
    write(1, "Error\ninvalid path", 19); // caso não tenha encontrado todos os coletáveis e a saída, o mapa não tem um caminho válido...
    return (0); // deu ruim
}
