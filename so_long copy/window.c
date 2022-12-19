/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:38:53 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 18:00:21 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//dimensiona a janela de acorco com a quantidade de elementos do mapa, inicia o ponteiro da mlx, inicializa o ponteiro da imagem
int	window(t_sl *game)
{
	game->w_width = IMG_SIZE * (game->map.col + 1); //dimensiona largura da a janela de acorco com a quantidade de elementos do mapa (a quantidade é sempre +1 em relação a posição)
	game->w_heigth = IMG_SIZE * (game->map.line + 1); //dimensiona a altura janela de acorco com a quantidade de elementos do mapa (a quantidade é sempre +1 em relação a posição)
	game->pt_mlx.mlx = mlx_init(); // inicia o ponteiro da mlx
	if (game->pt_mlx.mlx == NULL) // se a inicializaçao falhar
	{
		free_matrix_map(game); //limpamos a matriz do mapa
		return (0); // erro na abertura da janela
	}
	game->pt_mlx.mlx_window = mlx_new_window(game->pt_mlx.mlx, game->w_width, \
	game->w_heigth, "so_long - maclara-"); // inicializa o ponteiro da imagem
	if (game->pt_mlx.mlx_window == NULL ) // se a inicializaçao falhar
		return (0); // erro na abertura da janela
	return (1); // ok
}

// função que fecha a janela
int	destroyer_window(t_sl *game)
{
	free_matrix_map(game); // damos free na matriz do mapa
	if (!game->pt_mlx.mlx) // se o ponteiro da mlx já for nulo
		exit (0); // só sair que está tudo ok
	mlx_clear_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window); // limpamos a janela
	mlx_loop_end(game->pt_mlx.mlx); // finalizamos os loops da mlx
	if (game->image.collect.img != NULL) // se o ponteiro das imagens não for null
		mlx_destroy_image(game->pt_mlx.mlx, game->image.collect.img); // chamamos a função que destrói as imagens - pra cada tipo de imagem do mapa 
	if (game->image.empty.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.empty.img);
	if (game->image.player.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.player.img);
	if (game->image.wall.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.wall.img);
	if (game->image.exit.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.exit.img);
	mlx_destroy_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window); // chamamos a função que fecha a janela
	mlx_destroy_display(game->pt_mlx.mlx); // some com o display
	free(game->pt_mlx.mlx); // damos free no ponteiro da mlx
	exit (0); // saímos do programa.
	return (0); 
}
