/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:29:02 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/25 13:03:38 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void game_init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	(*game)->map = NULL;
	(*game)->name = NULL;
	(*game)->map_height = 0;
	(*game)->map_width = 0;
	(*game)->coin = 0;
	(*game)->player = 0;
	(*game)->exit = 0;
	(*game)->collected_coin = 0;
	(*game)->co_player = malloc(sizeof(t_co));
	(*game)->co_player->x = 0;
	(*game)->co_player->y = 0;
	(*game)->co_exit = malloc(sizeof(t_co));
	(*game)->co_exit->x = 0;
	(*game)->co_exit->y = 0;
	(*game)->co_coin = NULL;
}

void check_name(t_game *game, int i)
{
	if (i > 4 && game->name[i - 3] == '.' && game->name[i - 2] == 'b' && \
	game->name[i - 1] == 'e' && game->name[i] == 'r')
		return ;
	ft_printf("Error map must be a .ber.\n");
	free_all(game);
	exit(EXIT_FAILURE);
}

void map_init(t_game *game, char **av)
{
	game->name = gnl_strjoin(NULL, av[1]);
	check_name(game, ft_strlen(game->name) - 1);
	get_map_height(game, av);
	alloc_map(game, av);
}