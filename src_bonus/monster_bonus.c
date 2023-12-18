/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:54:10 by ritavasques       #+#    #+#             */
/*   Updated: 2023/11/08 15:37:14 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_spider(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'M')
			{
				data->mons_y = y;
				data->mons_x = x;
			}
			x++;
		}
		y++;
	}
}

void	move_monster(t_data *data)
{
	if (data->mons_y - 1 >= 0 && \
	data->map->map[data->mons_y - 1][data->mons_x] != '1')
	{
		if (data->map->map[data->mons_y][data->mons_x] != 'P')
			data->map->map[data->mons_y][data->mons_x] = '0';
		if (data->map->map[data->mons_y - 1][data->mons_x] == 'P')
			close_window(data);
		data->map->map[data->mons_y - 1][data->mons_x] = 'M';
		data->mons_y = data->mons_y - 1;
	}
	else if (data->mons_y + 1 <= data->lines && \
	data->map->map[data->mons_y + 1][data->mons_x] != '1')
	{
		if (data->map->map[data->mons_y][data->mons_x] != 'P')
			data->map->map[data->mons_y][data->mons_x] = '0';
		if (data->map->map[data->mons_y - 1][data->mons_x] == 'P')
			close_window(data);
		data->map->map[data->mons_y + 1][data->mons_x] = 'M';
	}
}
