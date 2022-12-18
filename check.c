/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:03:30 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 11:30:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_arguments(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        i = ft_strlen(argv[1]);
        if ((argv[1][i - 4] == '.') && (argv[1][i - 3] == 'b') && \
        (argv[1][i - 2] == 'e') && (argv[1][i - 1] == 'r'))
            return (1);
        else
        {
            write (1, "Error\nInvalid file format!\n", 28);    
            return (0);  
        }

    }
    write (1, "Error\nInvalid argument number!\n", 32);
    return (0);
}

char    **read_maps(char **argv)
{
    int     fd;
    int     read_bytes;
    char    buffer[2];
    char    *map;
    char    *temp;
    
    read_bytes = 1;
    fd = open (argv[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = ft_strdup("");
    //temp = ft_strdup("");
    while (1)
    {
        read_bytes = read(fd, buffer, 1);
        if (read_bytes == -1)
            return (NULL);
        else if (read_bytes == 0)
            break ;
        buffer[1] = '\0';
        temp = map;
        map = ft_strjoin(temp, buffer);
        free(temp);   
    }
    return (ft_split(map, '\n'));
}

int    validate_caracters_map(t_sl *game)
{
    int l;
    int c;
    
    c = 0;
    l = 0;
    while (game->map.map[l])
    {
        c = 0;
        while (game->map.map[l] && game->map.map[l][c])
        {
            if (game->map.map[l][c] && (game->map.map[l][c] != 'P' && \
            game->map.map[l][c] != 'C' && game->map.map[l][c] != 'E' && \
            game->map.map[l][c] != '0' && game->map.map[l][c] != '1'))
            {
                write(1,"Error\nCaracter invalid in map", 30);
                return (0);
            }
            c++;
        }
        l++;
    }
    return (1);
}

int    validate_itens_map(t_sl *game)
{
    int l;
    int c;
    
    l = 0;
    c = 0;
    while(game->map.map[l])
    {
        c = 0;
        while(game->map.map[l] && game->map.map[l][c])
        {
            if(game->map.map[l][c] && game->map.map[l][c] == 'P')
                game->vmap.p++;
            if(game->map.map[l][c] && game->map.map[l][c] == 'C')
                game->vmap.c++;
            if(game->map.map[l][c] && game->map.map[l][c] == 'E')
                game->vmap.e++;
            c++;
        }
        l++;
    }
    if (game->vmap.e != 1 || game->vmap.p != 1 || game->vmap.c == 0)
    {
        write(1, "Error\ninvalid itens on map", 27);
        return (0);
    }
    return (1);
}

int check_maps(char **argv, t_sl *game)
{
    game->map.map = read_maps(argv);
    if (game->map.map == NULL)
    {
        write (1, "Error\nmap error\n", 17);
        return (0);
    }
    init_validate_map(&game->vmap);
    if(validate_caracters_map(game) == 0)
        return (0);
    if(validate_itens_map(game) == 0)
        return (0);
    if(square_map(game) == 0)
        return (0);
    if (check_wall(game) == 0)
        return (0);
    return (1);
}
