/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:15:06 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/22 20:37:49 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_square(t_game *game)
{
	int i;
	size_t tmp;

	i = 0;
	tmp = ft_strlen(game->map[0]);
	while(i < game->map_height)
	{
		if(ft_strlen(game->map[i]) != tmp)
		{
			ft_printf("Map has to be a square or a retangle.\n");
			free_all(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	game->map_width = ft_strlen(game->map[i - 1]);
}

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[0][i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != '\0')
		{
			ft_printf("Map has to be surrounded by wall.\n");
			free_all(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while(game->map[game->map_height - 1][i])
	{
		if (game->map[game->map_height - 1][i] != '1' && game->map[game->map_height - 1][i] != '\0')
		{
			ft_printf("Map has to be surrounded by wall.\n");
			free_all(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while(i < game->map_height)
	{
		if(game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[0]) - 1] != '1')
		{
			ft_printf("Map has to be surrounded by wall.\n");
			free_all(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_value(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < game->map_height)
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'C')
				game->coin++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
			{
				ft_printf("Error only character allowed in the map are 0, 1, C, P and E.\n");
				free_all(game);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
} 