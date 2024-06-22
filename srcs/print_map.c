/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:31:57 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/18 15:28:55 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		ft_printf("%s\n", game->map[i++]);
	}
}