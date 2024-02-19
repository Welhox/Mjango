/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:05:30 by clundber          #+#    #+#             */
/*   Updated: 2024/02/19 14:55:27 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_image_up(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player/player_up1.png");
	if (!temp_img)
		return (-1);
	data->up[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->up[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player/player_up2.png");
	if (!temp_img)
		return (-1);
	data->up[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->up[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_down(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player/player_down1.png");
	if (!temp_img)
		return (-1);
	data->down[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->down[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player/player_down2.png");
	if (!temp_img)
		return (-1);
	data->down[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->down[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_left(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player/player_right1.png");
	if (!temp_img)
		return (-1);
	data->right[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->right[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player/player_right2.png");
	if (!temp_img)
		return (-1);
	data->right[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->right[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_right(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player/player_left1.png");
	if (!temp_img)
		return (-1);
	data->left[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->left[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player/player_left2.png");
	if (!temp_img)
		return (-1);
	data->left[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->left[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}