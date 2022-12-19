/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:21:58 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 10:55:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
# define so_long

# include <unistd.h> // write, read, 
# include <stdlib.h> // malloc, free,
# include <stdio.h>
# include <fcntl.h> // open,
# include "mlx.h" // biblioteca minilibx, vai entre aspas porque ela está na pasta do projeto e não instalada no pc como as outras bibliotecas

// para a func gnl
# define BUFFER_SIZE 1

// tamanho das imagens em pixels
# define IMG_SIZE 50//largura e altura é o mesmo (imagens quadradas)

// para o pressionar das teclas - VALORES PRÉ DEFINIDOS PELA X11
# define K_PRESS 2
# define K_MASKPRESS 1L<<0
# define K_PRESS_X 17
# define K_MASKPRESS_X 1L<<2

// definição das teclas para poder andar no jogo em hexadecimal
# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b

// definição das setas para poder andar no jogo em hexadecimal
# define AW_L 65361
# define AW_UP 65362
# define AW_R 65363
# define AW_DN 65364

typedef struct	s_mlx_pointer
{
	void	*mlx;
	void	*mlx_window;
}	t_mlx_p;

typedef struct	s_position
{
	int	x;
	int	y;
}	t_pos;

// struct da mlx 
typedef struct	s_images_datas
{
	void	*img;
	char	*addr; // talvez n use
	int		bits_per_pixel; // talvez n use
	int		line_len; // talvez n use
	int		endian; // talvez n use
}   t_img;

typedef struct	s_draw_objs
{
	t_img	wall;
	t_img	exit;
	t_img	collect;
	t_img	player;
	t_img	empty;
} t_draw;

typedef struct s_validmap
{
	int	c;
	int	p;
	int	e;
}	t_valmp;

typedef struct s_map
{
	char	**map;
	char	**b_map;
	t_pos	pla_pos;
	int		line;
	int		col;
	int		item;
}	t_map;

typedef struct s_so_long
{
	t_mlx_p	pt_mlx;
	t_map	map;
	t_draw	image;
	t_valmp	vmap;
	int		steps;
	int		collect;
	int		exit;
	int		w_width; // largura da janela
	int		w_heigth; // altura da janela
	int		end_game; // quando for 1, permite a saída do jogo
}	t_sl;

// utils
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int	    ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_strstr(const char *s1, const char *s2);
// gnl
char	*get_next_line(int fd);
// init
void    init_map(t_map  *map);
void	init_validate_map(t_valmp *vmap);
// read 
char    **read_maps(char **argv);
// check
int	check_maps(char **argv, t_sl *game);
int     check_arguments(int argc, char **argv);
// check2
int square_map(t_sl *game);
int check_wall(t_sl *game);
// valid_way
int 	valid_way(t_sl *game);
// window
int	window(t_sl *game);
int	destroyer_window(t_sl *game);
// game 
void    game_work(t_sl *game);
// move
void move_player(t_sl *game, int keycode, int col, int line);
// clear_map
void	free_matriz_map(t_sl *game);

#endif


//valgrind --leak-check=full --show-leak-kinds=all ./so_long bigmap.ber 