/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:09:42 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/22 17:14:23 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(t_game *game)
{
	*game->co_player = (t_co){0};
	while(game->co_player->y < game->map_height)
	{
		game->co_player->x = 0;
		while(game->map[game->co_player->y][game->co_player->x])
		{
			if (game->map[game->co_player->y][game->co_player->x] == 'P')
				return ;
			game->co_player->x++;
		}
		game->co_player->y++;
	}
	
}

void	find_exit(t_game *game)
{
	*game->co_exit = (t_co){0};
	while(game->co_exit->y < game->map_height)
	{
		game->co_exit->x = 0;
		while(game->map[game->co_exit->y][game->co_exit->x])
		{
			if (game->map[game->co_exit->y][game->co_exit->x] == 'E')
				return ;
			game->co_exit->x++;
		}
		game->co_exit->y++;
	}
	
}

void	find_coin(t_game *game)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	game->co_coin = ft_calloc(game->coin, sizeof(t_co_coin));
	if (!game->co_coin)
	{
		ft_printf("Error during memory allocation\n");
		free_all(game);
		exit(EXIT_FAILURE);
	}
	while(y < game->map_height)
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				game->co_coin[i].y = y;
				game->co_coin[i++].x = x;
			}
			x++;
		}
		y++;
	}
}

void	fill_pos(t_game *game)
{
	find_player(game);
	find_exit(game);
	find_coin(game);
}