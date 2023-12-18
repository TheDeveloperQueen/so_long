/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:12:37 by ritavasques       #+#    #+#             */
/*   Updated: 2023/11/08 21:07:10 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**read_map(char *map)
{
	int		fd;
	char	*temp_map;
	char	**map_read;
	int		bytesread;

	bytesread = 0;
	temp_map = (char *) ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp_map)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (NULL);
	}
	bytesread = read(fd, temp_map, BUFF_SIZE);
	if (bytesread <= 0)
	{
		free(temp_map);
		return (NULL);
	}
	map_read = ft_split(temp_map, '\n');
	free(temp_map);
	return (close(fd), map_read);
}

int	check_surrounded_walls(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if ((y == 0 || y == data->lines) && data->map->map[y][x] != '1' )
				return (0);
			if ((x == 0 || x == data->columns) && data->map->map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	put_img(int x, int y, t_data *data, char *path)
{
	int	img_w;
	int	img_h;

	data->map->img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, data->map->img, \
	(x * H_IMG), (y * W_IMG));
}

void	put_player(int x, int y, t_data *data)
{
	int	img_w;
	int	img_h;

	data->map->img = mlx_xpm_file_to_image(data->mlx, data->player_path, \
	&img_w, &img_h);
	mlx_put_image_to_window(data->mlx, data->win, data->map->img, \
	(x * H_IMG), (y * W_IMG));
}

int	ft_fill_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			put_img(x, y, data, BACKGROUND);
			if (data->map->map[y][x] == '1')
				put_img(x, y, data, WALL);
			else if (data->map->map[y][x] == 'C')
				put_img(x, y, data, COLLECT);
			else if (data->map->map[y][x] == 'E')
				put_img(x, y, data, EXIT);
			else if (data->map->map[y][x] == 'P')
				put_player(x, y, data);
			else if (data->map->map[y][x] == 'M')
				put_img(x, y, data, MONSTER);
			x++;
		}
		y++;
	}
	return (0);
}
