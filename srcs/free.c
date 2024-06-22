/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:18:14 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/22 15:48:14 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	free(game->co_player);
	free(game->co_exit);
	if (game->co_coin)
		free(game->co_coin);
	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
	free(game);
}