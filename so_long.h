/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:21:58 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 13:00:11 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
# define so_long

# include <unistd.h> // write, read, 
# include <stdlib.h> // malloc, free,
# include <stdio.h>
# include <fcntl.h> // open,
# include "mlx.h" // biblioteca minilibx, vai entre aspas porque ela está na pasta do projeto e não instalada no pc como as outras bibliotecas

# define BUFFER_SIZE 1

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

typedef struct	s_images_datas
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
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
}	t_sl;

//utils
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int	    ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
//gnl
char	*get_next_line(int fd);
//main
void	window_and_image(void);
void    open_window(void *mlx);
void	init_and_put_image(void *mlx);
// init
void    init_map(t_map  *map);
void	init_validate_map(t_valmp *vmap);
// read 
char    **read_maps(char **argv);
//check
int	check_maps(char **argv, t_sl *game);
int     check_arguments(int argc, char **argv);
int    validate_caracters_map(t_sl *game);
void msg_error_itens(t_sl *game);
int    validate_itens_map(t_sl *game);
//check2
int square_map(t_sl *game);
int check_vertical_wall(t_sl *game);
int check_horizontal_wall(t_sl *game);
int check_wall(t_sl *game);
// valid_way
void    player_position(t_sl *game);
void    flood_fill(t_sl *game, int  px, int py);
int 	valid_way(t_sl *game);

#endif