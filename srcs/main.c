/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:03:33 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/22 16:12:49 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	check_map(game);
	free_all(game);
    return (0);
}