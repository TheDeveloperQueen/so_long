/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:36:29 by rivasque          #+#    #+#             */
/*   Updated: 2023/11/10 10:51:50 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_data(t_data *data)
{
	data->map = (t_map *)malloc(sizeof(t_map));
}

static void	init_map(t_data *data)
{
	int	x;
	int	y;

	data->treasure = count_components(data, 'C');
	data->count = 0;
	data->player_path = PLAYER;
	y = 0;
	x = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map->map[y][x] == 'P')
			{
				data->py = y;
				data->px = x;
			}
			x++;
		}
		y++;
	}
}

static void	manage_win(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->size_x, data->size_y, \
	"Treasure Hunt");
	ft_fill_map(data);
	mlx_key_hook(data->win, &move_player, data);
	mlx_hook(data->win, 17, 0, &close_window, data);
}

/*void	leaks()
{
	system("leaks -q so_long");
}*/
//atexit(leaks);

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2 || !check_ber(argv[1]))
		return (ft_printf("Error\nINVALID ARGUMENT\n"));
	fd = open(argv[1], O_RDONLY);
	init_data(&data);
	data.columns = ft_line_length(fd);
	close(fd);
	data.size_x = (data.columns) * W_IMG;
	(data.map)->map = read_map(argv[1]);
	data.lines = ft_line_count((data.map)->map);
	data.size_y = (data.lines) * H_IMG;
	init_map(&data);
	if (!map_ok(&data))
	{
		free_map(&data);
		free(data.map->map);
		ft_printf("Error\nINVALID MAP\n");
		exit (EXIT_SUCCESS);
	}
	manage_win(&data);
	mlx_loop(data.mlx);
	return (0);
}
