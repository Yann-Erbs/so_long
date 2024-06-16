/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:29:02 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/16 04:31:47 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void game_init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	(*game)->map = NULL;
	(*game)->map_height = 0;
	(*game)->map_width = 0;
}

void map_init(t_game *game, char **av)
{
	get_map_height(game, av);
	alloc_map(game, av);
}