/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:03:33 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/16 04:32:34 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
		free(game->map[i++]);
}

int main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
    {
        ft_printf("Invalide number of argument.\n");
        return (1);
	}
    game_init(&game);
	map_init(game, av);
	print_map(game);
	free_map(game);
	free(game);
    return (0);
}

