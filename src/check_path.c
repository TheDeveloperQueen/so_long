/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:10 by rivasque          #+#    #+#             */
/*   Updated: 2023/11/10 10:50:11 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_path(char **map_cpy, int y, int x)
{
	int	check;

	check = 0;
	if (map_cpy[y][x] == 'E')
		return (1);
	else
		map_cpy[y][x] = '1';
	if (map_cpy[y][x - 1] != '1')
		check += find_path(map_cpy, y, x - 1);
	if (map_cpy[y][x + 1] != '1')
		check += find_path(map_cpy, y, x + 1);
	if (map_cpy[y - 1][x] != '1')
		check += find_path(map_cpy, y - 1, x);
	if (map_cpy[y + 1][x] != '1')
		check += find_path(map_cpy, y + 1, x);
	return (check);
}

static void	check_treasure(int *res, char **map_cpy)
{
	int	x;
	int	y;

	y = 0;
	if (*res == 0)
		return ;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == 'C')
			{
				*res = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_path(t_data *data)
{
	char	**map_cpy;
	int		y;
	int		check;

	y = 0;
	map_cpy = (char **)malloc((data->lines + 1) * sizeof(char *));
	if (!map_cpy)
		return (0);
	while (data->map->map[y])
	{
		map_cpy[y] = ft_strdup(data->map->map[y]);
		y++;
	}
	map_cpy[y] = NULL;
	check = find_path(map_cpy, data->py, data->px);
	check_treasure(&check, map_cpy);
	y = 0;
	while (map_cpy[y])
		free(map_cpy[y++]);
	free(map_cpy);
	return (check);
}
