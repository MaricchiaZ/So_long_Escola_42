/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:49:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 17:15:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// analisa o movimento solicitado pela tecla pressionada e vê se é possível (impede do player passar pelas paredes e por cima da saída)
static int	move_be_ok(t_sl *game, int keycode, int line, int col)
{
	if (game->map.map[line][col] == '1') // se for parede
		return (0); // n permite andar
	if (game->map.map[line][col] == 'E' && game->vmap.c == 0) // se for saída e tiver coletado tudo
		game->end_game = 1; // a permissão de saída ocorre, a  possibilidade de finalizar o jogo 'game->end_game' vira 1;
	if (game->map.map[line][col] == 'E') // se for a saída
		return (0); // n permite andar, optei pelo personagem não passar sobre o desenho da saída e o jogo finaliza com ele posicionado ao lado da saída
	if (game->end_game) // com a permissão dada
		return (0); //não pode mais mexer
	if (keycode == W || keycode == S || keycode == A || keycode == D || \
	keycode == AW_UP || keycode == AW_DN || keycode == AW_L || \
	keycode == AW_R) // se for alguma dessas teclas e o movimento não tiver impedido
		return (1); // movimentação autorizada
	return (0); // senão, movimentação impedida
}

// função que movimenta o player
void	move_player(t_sl *game, int keycode, int col, int line)
{
	char	*temp;
	int		px; // coordenada do player
	int		py; // coordenada do player
	int		move_ok; // recebe a autorização do movimento

	px = game->map.pla_pos.x; // coordenada do player
	py = game->map.pla_pos.y; // coordenada do player
	move_ok = move_be_ok(game, keycode, line, col); //autorização do movimento
	if (move_ok > 0) // autorizado
	{
		if (game->map.map[line][col] == 'C') // se for um coletável
			game->vmap.c--; // número de coletáveis perde uma unidade
		game->map.map[px][py] = '0'; // a posição atual vira caminho '0'
		game->map.map[line][col] = 'P'; // a posição para a qual se está indo vira o player 'P'
		game->map.pla_pos.y = col; // a posição do player é atualizada
		game->map.pla_pos.x = line; // a posição do player é atualizada
		game->steps++; //conta-se mais um passo
		temp = ft_itoa(game->steps); // o int game->steps é transformado em string
		ft_putstr("Steps move: "); // imprimimos a mensagem
		ft_putstr(temp); // o número de passos
		ft_putstr("\n"); // a quebra de linha
		free(temp); // liberamos o ponteiro da string temporária
	}
}
