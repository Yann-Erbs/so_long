/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:29:02 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/22 16:18:59 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void game_init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	(*game)->map = NULL;
	(*game)->map_height = 0;
	(*game)->map_width = 0;
	(*game)->coin = 0;
	(*game)->player = 0;
	(*game)->exit = 0;
	(*game)->collected_coin = 0;
	
	(*game)->co_player = malloc(sizeof(t_co));
	//(*game)->co_player->x = 0;
	//(*game)->co_player->y = 0;

	(*game)->co_exit = malloc(sizeof(t_co));
	//(*game)->co_exit->x = 0;
	//(*game)->co_exit->y = 0;

	/*(*game)->co_coin = ft_calloc((*game)->coin, sizeof(t_co_coin));
	(*game)->co_coin->x = 0;
	(*game)->co_coin->y = 0;
	(*game)->co_coin->is_collected = 0;*/

}

void map_init(t_game *game, char **av)
{
	get_map_height(game, av);
	alloc_map(game, av);
}