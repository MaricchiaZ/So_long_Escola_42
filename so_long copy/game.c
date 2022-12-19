/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:09:49 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 16:31:46 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ESQUELETO CENTRAL DO JOGO

// função que abre as imagens que compõe o jogo
static int	open_images(t_sl *game)
{
	int	x; // coordenada de encaixe da imagem (exigido pela mlx, não se preocupe com ela)
	int	y; // coordenada de encaixe da imagem (exigido pela mlx, não se preocupe com ela)

	x = 0;
	y = 0;
	// o ponteiro 'game->image.collect.img' recebe a imagem da func mlx_xpm_file_to_image
	// para todos os ítes: C, P, E, 0 e 1
	game->image.collect.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/collect.xpm", &x, &y); 
	game->image.player.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/player.xpm", &x, &y);
	game->image.empty.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/empty.xpm", &x, &y);
	game->image.wall.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/wall.xpm", &x, &y);
	game->image.exit.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/exit.xpm", &x, &y);
	// vamos conferir se as imagens foram encontradas
	if (game->image.collect.img == NULL || game->image.player.img == NULL || \
	game->image.empty.img == NULL || game->image.wall.img == NULL || \
	game->image.exit.img == NULL ) // algum pomteiro para as imagens for NULL
		destroyer_window(game); // fechamos a janela
	return (1); //ok
}

// posiçiona cada imagem (asset) em seu lugar, de acordo com o  caracter do mapa
// essa função coloca apenas uma imagem por vez
static void	put_one_image(t_sl *game, int line, int col)
{
	if (game->map.map[line] && game->map.map[line][col] == '1') // se a linha existir e o conteúdo da coluna for 1
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.wall.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem da parede
	else if (game->map.map[line] && game->map.map[line][col] == '0') // se a linha existir e o conteúdo da coluna for 0
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.empty.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem do caminho / empty
	else if (game->map.map[line] && game->map.map[line][col] == 'P') // se a linha existir e o conteúdo da coluna for P
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.player.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem do player
	else if (game->map.map[line] && game->map.map[line][col] == 'C') // se a linha existir e o conteúdo da coluna for C
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.collect.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem do coletável
	else if (game->map.map[line] && game->map.map[line][col] == 'E') // se a linha existir e o conteúdo da coluna for E
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.exit.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem da saída
}

// função que lê o mapa e coloca a imagem adequada
static int	game_draw(t_sl *game)
{
	int	line; // para percorrer o mapa
	int	col; // para percorrer o mapa

	line = 0;
	while (line <= game->map.line) // enquanto ainda tiver linha para ler
	{
		col = 0;
		while (col <= game->map.col) // enquanto ainda tiver coluna na linha pra ler
		{
			put_one_image(game, line, col); // coloca-se a imagem adequada
			col++; // próxima coluna
		}
		line++; // proxima linha
	}
	if (game->end_game) // se o game->end_game for diferente de zero, o jogador ganhou o jogo
		mlx_string_put(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->w_width / 2 - 25, game->w_heigth / 2, 0xFFF, "You Win!!!"); // usamos essa função 'mlx_string_put' para escrever na tela 
	return (1); //ok
}

// recebe as infos das teclas acionadas
static int	recipe_key(int keycode, t_sl *game)
{
	int	line; // para movumentar o player na tela
	int	col; // para movumentar o player na tela

	line = game->map.pla_pos.x; // sim, em C é invertido :)
	col = game->map.pla_pos.y;  // sim, em C é invertido ;)
	if (keycode == ESC) // esc fecha a janela
		destroyer_window(game);
	if (keycode == W || keycode == AW_UP) // move o o player pra cima
		line--;
	if (keycode == S || keycode == AW_DN)  // move o o player pra baixo
		line++;
	if (keycode == A || keycode == AW_L)  // move o o player pra esquerda
		col--;
	if (keycode == D || keycode == AW_R)  // move o o player pra direita
		col++;
	if (!game->end_game) // se game->end_game == 0, não coletou-se tudo e a movimentação ainda é possível / game->end_game será 1 ao se coletar tudo e chegar na saída
		move_player(game, keycode, col, line); // func qie move o player
	return (1); // ok
}

// funçao que orquestra as funções que abrem a janela, abrem as imagens, recebem os cliques das teclas (movimentação do player), clique no botão de fechar a tela, o loop da imagem na tela, e o loop as funções da mlx
void	game_work(t_sl *game)
{
	window(game); // inicializa a mlx, a janela e a imagem
	open_images(game); // abre as imagens dos componentes do jogo
	mlx_hook(game->pt_mlx.mlx_window, K_PRESS, 1L << 0, &recipe_key, game); // cliques do teclado, pra jogar
	mlx_hook(game->pt_mlx.mlx_window, K_PRESS_X, 1L << 2, \
	&destroyer_window, game); // clique do esc, pra fechar a janela
	mlx_loop_hook(game->pt_mlx.mlx, &game_draw, game); // desenha o jogo
	mlx_loop(game->pt_mlx.mlx); // mantém as func da mlx em loop
}
