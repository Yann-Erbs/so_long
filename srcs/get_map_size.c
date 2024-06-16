/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:09:07 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/16 02:27:49 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_height(t_game *game, char **av)
{
    char    *line;
	int		fd;

	fd = fd_manager(av[1]);
	line = get_next_line(fd);
    while (line)
    {
        game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}