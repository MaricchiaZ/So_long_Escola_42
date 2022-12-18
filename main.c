/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:21:06 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 09:36:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_sl    game;
    if (check_arguments(argc, argv) == 0)
        return (-1);
    game.steps = 0;
    if (check_maps (argv, &game) == 0)
        return (-1);
    for(int i = 0; game.map.map[i]; i++)
        printf("%s\n", game.map.map[i]);
    return 0;
}
