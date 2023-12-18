/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:19:00 by ritavasques       #+#    #+#             */
/*   Updated: 2023/11/10 10:55:12 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_format(t_data *data)
{
	if (data->lines != data->columns)
		return (1);
	else
		return (0);
}

int	count_components(t_data *data, char c)
{
	int	objects;
	int	y;
	int	x;

	objects = 0;
	x = 0;
	y = 0;
	while (y < data->lines)
	{
		while (x < data->columns)
		{
			if (data->map->map[y][x] == c)
				objects++;
			x++;
		}
		x = 0;
		y++;
	}
	return (objects);
}

int	check_component_type(t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < data->lines)
	{
		while (x < data->columns)
		{
			if (data->map->map[y][x] != '0' && \
			data->map->map[y][x] != '1' && \
			data->map->map[y][x] != 'P' && \
			data->map->map[y][x] != 'E' && \
			data->map->map[y][x] != 'C' && \
			data->map->map[y][x] != 'M')
			{
				return (1);
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	check_components(t_data *data)
{
	if (count_components(data, 'E') == 1 \
	&& count_components(data, 'C') >= 1 \
	&& count_components(data, 'P') == 1)
		return (1);
	return (0);
}

int	map_ok(t_data *data)
{
	if (check_surrounded_walls(data) && check_format(data) && \
	check_components(data) && !check_component_type(data) && \
	check_path_bonus(data) > 0)
		return (1);
	return (0);
}
