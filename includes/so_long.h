/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:20:28 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/21 16:09:16 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct s_co
{
	int				x;
	int				y;
} t_co;

typedef struct s_co_coin
{
	int				x;
	int				y;
	int				is_collected;
}	t_co_coin;

typedef struct s_game
{
	char			**map;
	int				map_height;
	int				map_width;
	int				coin;
	int				exit;
	int				player;
	int				collected_coin;
	t_co			*co_player;
	t_co			*co_exit;
	t_co_coin		*co_coin;
} t_game;

void	get_map_height(t_game *game, char **av);
void	alloc_map(t_game *game, char **av);
void 	map_init(t_game *game, char **av);
void	game_init(t_game **game);
void	print_map(t_game *game);
void	check_map(t_game *game);
void	free_all(t_game *game);
void	check_wall(t_game *game);
void	check_square(t_game *game);
void	check_value(t_game *game);
void	find_player(t_game *game);
void	find_exit(t_game *game);
void	find_coin(t_game *game);
void	fill_pos(t_game *game);
void	find_path(t_game *game, int x, int y);

int		fd_manager(char *av);

#endif
