/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:04:43 by rivasque          #+#    #+#             */
/*   Updated: 2023/11/08 12:06:53 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && \
	str[i - 3] == '.')
		return (1);
	else
		return (0);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map)
	{
		while (data->map->map[i])
		{
			free(data->map->map[i]);
			i++;
		}
	}
}

int	close_window(t_data *data)
{
	ft_printf("THE END");
	mlx_destroy_window(data->mlx, data->win);
	free_map(data);
	exit (EXIT_SUCCESS);
}
