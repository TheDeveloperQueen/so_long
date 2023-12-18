/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:39:01 by ritavasques       #+#    #+#             */
/*   Updated: 2023/11/09 10:22:38 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define PLAYER "./img/PLAYER.xpm"
# define PLAYERF0 "./img/playerf0.xpm"
# define PLAYERF1 "./img/playerf1.xpm"
# define PLAYERB0 "./img/playerb0.xpm"
# define PLAYERB1 "./img/playerb1.xpm"
# define PLAYERL0 "./img/playerl0.xpm"
# define PLAYERL1 "./img/playerl1.xpm"
# define PLAYERR0 "./img/playerr0.xpm"
# define PLAYERR1 "./img/playerr1.xpm"
# define COLLECT "./img/COLECT.xpm"
# define WALL "./img/WALL.xpm"
# define EXIT "./img/EXIT.xpm"
# define BACKGROUND "./img/Background.xpm"
# define ESC 53
# define UP 126
# define W 13
# define DOWN 125
# define A 0
# define LEFT 123
# define S 1
# define RIGHT 124
# define D 2
# define H_IMG 50
# define W_IMG 50
# define BUFF_SIZE 1000

typedef struct s_map
{
	char	**map;
	void	*img;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size_x;
	int		size_y;
	int		lines;
	int		px;
	int		py;
	int		columns;
	int		count;
	int		treasure;
	char	*player_path;
	t_map	*map;
}			t_data;

int		close_window(t_data *data);
int		check_ber(char *str);
int		count_components(t_data *data, char c);
int		check_component_type(t_data *data);
int		check_components(t_data *data);
int		check_format(t_data *data);
int		map_ok(t_data *data);
char	**read_map(char *map);
int		move_player(int keycode, t_data *data);
int		ft_fill_map(t_data *data);
int		check_surrounded_walls(t_data *data);
void	free_map(t_data *data);
int		check_path(t_data *data);
void	put_img(int x, int y, t_data *data, char *path);
void	put_player(int x, int y, t_data *data);

#endif