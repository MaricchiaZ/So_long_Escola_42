/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:49:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 18:06:16 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_be_ok(t_sl *game, int keycode, int line, int col)
{
	if (game->map.map[line][col] == '1')
		return (0); // mov não possível
	if (game->map.map[line][col] == 'E' && game->vmap.c == 0)
		game->end_game = 1; // recebendo um, os mov são paralizados e o jogo acaba
	if (game->map.map[line][col] == 'E')
		return (0); // não pode passar sobre a saída para não apagar o desenho dela
	if (game->end_game)
		return(0); // achou a saída e não pode mais andar
	if (keycode == W || keycode == S || keycode == A || keycode == D || \
	keycode == AW_UP || keycode == AW_DN || keycode == AW_L || \
	 keycode == AW_R) // se for uma tecla válida para os movimentos
		return (1); // TRUE, movimento válido
	return (0); // mov não possível
}

// line e col já vem modificadas pela tecla apertada
int move_player(t_sl *game, int keycode, int line, int col)
{
	char	*temp;
	int	px; //valor x da posição do player
	int	py; //valor y da posição do player
	int	move_ok; //valida se a posição que o player quer alcançar é ok

	px = game->map.pla_pos.x; // salvamos a posição atual do player
	py = game->map.pla_pos.y; // salvamos a posição atual do player
	move_ok = move_be_ok(game, keycode, line, col); 
	if (move_ok > 0) // só movemos se o movimento for possível (ele não passará em cima de uma parede)
	{
		if (game->map.map[line][col] == 'C') // ao encontrar um coletável
			game->vmap.c--; // consumimos o mesmo
		game->map.map[py][px] = '0'; // mudamos a info do mapa pra 0 (caminho livre)
		game->map.map[line][col] = 'P'; // mudamos a info do mapa P (player)
		game->map.pla_pos.x = col; // posição nova do player
		game->map.pla_pos.y = line; //posição nova do player
		game->steps++;
		temp = ft_itoa(game->steps);
		ft_putstr("Steps move: ");
		ft_putstr(temp);
		ft_putstr("\n");
	}
}
