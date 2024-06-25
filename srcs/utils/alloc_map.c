/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:22:14 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/25 13:05:06 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void remove_newline(char *line) {
    size_t len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';  // Remplace \n par \0
    }
}

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
		remove_newline(line); 
		game->map[j] = line;
		j++;
		line = get_next_line(fd);
	}
	close(fd);
}