/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:18:14 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/25 13:05:15 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->co_player)
		free(game->co_player);
	if (game->co_exit)
		free(game->co_exit);
	if (game->co_coin)
		free(game->co_coin);
	if (game->name)
		free(game->name);
	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
	free(game);
}