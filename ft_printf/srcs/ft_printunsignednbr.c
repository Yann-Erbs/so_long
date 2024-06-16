/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignednbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:53:50 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/13 23:34:39 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printunsignednbr(unsigned int n)
{
	int		len;
	char	*tab;

	len = 0;
	tab = ft_uitoa(n);
	len = ft_printstr(tab);
	free(tab);
	return (len);
}
