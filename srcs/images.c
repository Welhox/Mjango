/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:24:10 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 16:05:18 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_image_terrain(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/rock_wall.png");
	if (!temp_img)
		return (-1);
	data->wall = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->wall)
		return (-1);
	mlx_delete_texture(temp_img);
	mlx_resize_image(data->wall, TX_SIZE, TX_SIZE);
	temp_img = mlx_load_png("./assets/Tile01.png");
	if (!temp_img)
		return (-1);
	data->floor = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->floor)
		return (-1);
	mlx_delete_texture(temp_img);
	mlx_resize_image(data->floor, TX_SIZE, TX_SIZE);
	return (0);
}

int	map_image_assets(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/collect.png");
	if (!temp_img)
		return (-1);
	data->collect = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->collect)
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/cave.png");
	if (!temp_img)
		return (-1);
	data->cave = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->cave)
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

void	image_init(t_data *data)

{
	if (map_image_terrain(data) == -1)
		data->error = true;
	if (data->error == false && map_image_assets(data) == -1)
		data->error = true;
	if (data->error == false && player_image_up(data) == -1)
		data->error = true;
	if (data->error == false && player_image_down(data) == -1)
		data->error = true;
	if (data->error == false && player_image_left(data) == -1)
		data->error = true;
	if (data->error == false && player_image_right(data) == -1)
		data->error = true;
	if (data->error == true)
	{
		mlx_terminate(data->mlx_ptr);
		ft_arrfree(data->map);
		error_func("Unable to load textures\n");
	}
}
