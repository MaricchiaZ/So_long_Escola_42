/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:01:32 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/18 15:22:55 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_maps(char **argv)
{
	int		fd;
	int		read_bytes;
	char	buffer[2];
	char	*map;
	char	*temp;
	
	read_bytes = 1;
	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_strdup("");
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
	close(fd);
	return (ft_split(map, '\n'));
}