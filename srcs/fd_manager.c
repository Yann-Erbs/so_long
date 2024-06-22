/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:20:35 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/21 15:13:38 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fd_manager(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error oppening file.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}