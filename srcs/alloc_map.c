/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:22:14 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/16 04:35:34 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	alloc_map(t_game *game, char **av)
{
	char	*line;
	int		fd;
	int		j;

	j = 0;
	game->map = (char **)malloc(sizeof(char *) * game->map_height);
	if (!game->map)
	{
		ft_printf("Error during memory allocation.\n");
		exit(EXIT_FAILURE);
	}
	fd =  fd_manager(av[1]);
	line = get_next_line(fd);
	while (line)
	{
		game->map[j] = line;
		j++;
		line = get_next_line(fd);
	}
	close(fd);
}