/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:02:40 by ritavasques       #+#    #+#             */
/*   Updated: 2023/11/08 20:52:37 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_up(t_data *data)
{
	if (data->py - 1 >= 0)
	{
		if (data->map->map[data->py - 1][data->px] == 'C')
			data->treasure--;
		if (data->map->map[data->py - 1][data->px] != '1' && \
		(data->map->map[data->py - 1][data->px] != 'E' || data->treasure == 0))
		{
			if (data->map->map[data->py - 1][data->px] == 'E' || \
			data->map->map[data->py - 1][data->px] == 'M')
				close_window(data);
			data->map->map[data->py][data->px] = '0';
			data->map->map[data->py - 1][data->px] = 'P';
			data->py = data->py - 1;
			data->count++;
			ft_printf("Movements: %d\n", data->count);
			if (data->count % 2 == 0)
				data->player_path = PLAYERB0;
			else
				data->player_path = PLAYERB1;
			move_monster(data);
			ft_fill_map(data);
			print_movements(data);
		}
	}
}

static void	move_down(t_data *data)
{
	if (data->py + 1 <= data->lines)
	{
		if (data->map->map[data->py + 1][data->px] == 'C')
			data->treasure--;
		if (data->map->map[data->py + 1][data->px] != '1' && \
		(data->map->map[data->py + 1][data->px] != 'E' || data->treasure == 0))
		{
			if (data->map->map[data->py + 1][data->px] == 'E' \
			|| data->map->map[data->py + 1][data->px] == 'M')
				close_window(data);
			data->map->map[data->py][data->px] = '0';
			data->map->map[data->py + 1][data->px] = 'P';
			data->py = data->py + 1;
			data->count++;
			ft_printf("Movements: %d\n", data->count);
			if (data->count % 2 == 0)
				data->player_path = PLAYERB0;
			else
				data->player_path = PLAYERB1;
			move_monster(data);
			ft_fill_map(data);
			print_movements(data);
		}
	}
}

static void	move_left(t_data *data)
{
	if (data->px >= 0)
	{
		if (data->map->map[data->py][data->px - 1] == 'C')
			data->treasure--;
		if (data->map->map[data->py][data->px - 1] != '1' && \
		(data->map->map[data->py][data->px - 1] != 'E' || data->treasure == 0))
		{
			if (data->map->map[data->py][data->px - 1] == 'E' || \
			data->map->map[data->py][data->px - 1] == 'M')
				close_window(data);
			data->map->map[data->py][data->px] = '0';
			data->map->map[data->py][data->px - 1] = 'P';
			data->px = data->px - 1;
			data->count++;
			ft_printf("Movements: %d\n", data->count);
			if (data->count % 2 == 0)
				data->player_path = PLAYERL0;
			else
				data->player_path = PLAYERL1;
			move_monster(data);
			ft_fill_map(data);
			print_movements(data);
		}
	}
}

static void	move_right(t_data *data)
{
	if (data->px <= data->columns)
	{
		if (data->map->map[data->py][data->px + 1] == 'C')
			data->treasure--;
		if (data->map->map[data->py][data->px + 1] != '1' && \
		(data->map->map[data->py][data->px + 1] != 'E' || data->treasure == 0))
		{
			if (data->map->map[data->py][data->px + 1] == 'E' || \
			data->map->map[data->py][data->px + 1] == 'M')
				close_window(data);
			data->map->map[data->py][data->px] = '0';
			data->map->map[data->py][data->px + 1] = 'P';
			data->px = data->px + 1;
			data->count++;
			ft_printf("Movements: %d\n", data->count);
			if (data->count % 2 == 0)
				data->player_path = PLAYERR0;
			else
				data->player_path = PLAYERR1;
			move_monster(data);
			ft_fill_map(data);
			print_movements(data);
		}
	}
}

int	move_player(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	if (keycode == UP || keycode == W)
		move_up(data);
	if (keycode == DOWN || keycode == A)
		move_down(data);
	if (keycode == RIGHT || keycode == D)
		move_right(data);
	if (keycode == LEFT || keycode == S)
		move_left(data);
	return (0);
}
