/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:00:23 by ritavasques       #+#    #+#             */
/*   Updated: 2023/11/08 15:42:17 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movements(t_data *data)
{
	char	*count;

	count = ft_itoa(data->count);
	mlx_string_put(data->mlx, data->win, 75, 75, 0x00FF00FF, count);
	free(count);
}
