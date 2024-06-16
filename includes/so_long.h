/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:20:28 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/16 02:18:41 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct s_game
{
	char	**map;
	int		map_height;
	int		map_width;
	
} t_game;

void	get_map_height(t_game *game, char **av);
void	alloc_map(t_game *game, char **av);
void 	map_init(t_game *game, char **av);
void	game_init(t_game **game);
void	print_map(t_game *game);

int		fd_manager(char *av);

#endif
