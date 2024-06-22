/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:44:15 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/21 16:16:32 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_path(t_game *game, int x, int y)
{
	if (game->map_width < x || y > game->map_height || game->map[y][x] == '1' || game->map[y][x] == 'V')
		return ;
	game->map[y][x] = 'V';
	find_path(game, x + 1, y);
	find_path(game, x, y + 1);
	find_path(game, x - 1, y);
	find_path(game, x, y - 1);
}

void	check_path(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	while (x < game->map_height - 1)
	{
		y = 1;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'C' || game->map[x][y] == 'E')
			{
				free_all(game);
				ft_printf("Error all coin as to be reachable and the exit too.\n");
				exit(EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
}

void	check_map(t_game *game)
{
	check_square(game);
	check_wall(game);
	check_value(game);
	if (game->exit != 1 || game->player != 1 || !game->coin)
	{
		ft_printf("Map has to have only one player, only one exit and at minimum one coin.\n");
		free_all(game);
		exit(EXIT_FAILURE);
	}
	fill_pos(game);
	find_path(game, game->co_player->x, game->co_player->y);
	check_path(game);
}
