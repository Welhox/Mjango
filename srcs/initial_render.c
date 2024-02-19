/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:53:30 by clundber          #+#    #+#             */
/*   Updated: 2024/02/19 16:02:17 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_render(t_data *data)

{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_image_to_window(data->mlx_ptr, data->wall_img,
					(x * TX_SIZE), (y * TX_SIZE));
			else
				mlx_image_to_window(data->mlx_ptr, data->grass_img,
					x * TX_SIZE, y * TX_SIZE);
			if (data->map[y][x] == 'C')
				mlx_image_to_window(data->mlx_ptr, data->collect,
					x * TX_SIZE, y * TX_SIZE);
			else if (data->map[y][x] == 'E')
			{
				mlx_image_to_window(data->mlx_ptr, data->cave,
					x * TX_SIZE, y * TX_SIZE);
				data->cave->instances->enabled = 0;
			}
			x++;
		}
		y++;
	}
}

void	player_render(t_data *data)

{
	mlx_image_to_window(data->mlx_ptr, data->down[0],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->down[1],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->up[0],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->up[1],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->left[0],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->left[1],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->right[0],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->right[1],
		data->pos_x * TX_SIZE, data->pos_y * TX_SIZE);
	player_image(data);
	data->down[0]->instances->enabled = 1;
}

void	player_image(t_data *data)

{
	data->down[0]->instances->enabled = 0;
	data->down[1]->instances->enabled = 0;
	data->up[0]->instances->enabled = 0;
	data->up[1]->instances->enabled = 0;
	data->left[0]->instances->enabled = 0;
	data->left[1]->instances->enabled = 0;
	data->right[0]->instances->enabled = 0;
	data->right[1]->instances->enabled = 0;
}
