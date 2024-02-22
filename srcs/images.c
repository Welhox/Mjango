/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:24:10 by clundber          #+#    #+#             */
/*   Updated: 2024/02/22 21:20:53 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_image_terrain(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/tree.png");
	if (!temp_img)
		return (-1);
	data->wall = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->wall)
		return (-1);
	mlx_delete_texture(temp_img);
	mlx_resize_image(data->wall, TX_SIZE, TX_SIZE);
	temp_img = mlx_load_png("./assets/dirt1.png");
	if (!temp_img)
		return (-1);
	data->floor = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->floor)
		return (-1);
	mlx_delete_texture(temp_img);
	mlx_resize_image(data->floor, TX_SIZE, TX_SIZE);
	return (0);
}

int	collect_image1(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/duck/duck1.png");
	if (!temp_img)
		return (-1);
	data->collect[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	mlx_resize_image(data->collect[0], TX_SIZE, TX_SIZE);
	if (!data->collect[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/duck/duck2.png");
	if (!temp_img)
		return (-1);
	data->collect[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	mlx_resize_image(data->collect[1], TX_SIZE, TX_SIZE);
	if (!data->collect[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	collect_image2(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/duck/duck3.png");
	if (!temp_img)
		return (-1);
	data->collect[2] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	mlx_resize_image(data->collect[2], TX_SIZE, TX_SIZE);
	if (!data->collect[2])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/duck/duck4.png");
	if (!temp_img)
		return (-1);
	data->collect[3] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	mlx_resize_image(data->collect[3], TX_SIZE, TX_SIZE);
	if (!data->collect[3])
		return (-1);
	mlx_delete_texture(temp_img);
	data->collect[4] = NULL;
	return (0);
}

int	map_image_assets(t_data *data)

{
	if (exit_image(data) == -1)
		return (-1);
	if (collect_image1(data) == -1)
		return (-1);
	if (collect_image2(data) == -1)
		return (-1);
	if (map_image_terrain(data) == -1)
		return (-1);
	return (0);
}

void	image_init(t_data *data)

{
	if (data->error == false && map_image_assets(data) == -1)
		data->error = true;
	if (data->error == false && player_image_up(data) == -1)
		data->error = true;
	if (data->error == false && player_image_up2(data) == -1)
		data->error = true;
	if (data->error == false && player_image_down(data) == -1)
		data->error = true;
	if (data->error == false && player_image_down2(data) == -1)
		data->error = true;
	if (data->error == false && player_image_left(data) == -1)
		data->error = true;
	if (data->error == false && player_image_left2(data) == -1)
		data->error = true;
	if (data->error == false && player_image_right(data) == -1)
		data->error = true;
	if (data->error == false && player_image_right2(data) == -1)
		data->error = true;
	if (data->error == true)
	{
		mlx_terminate(data->mlx_ptr);
		ft_arrfree(data->map);
		error_func("Unable to load textures\n");
	}
}
