/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:05:30 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 23:57:50 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_image_up(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/up1.png");
	if (!temp_img)
		return (-1);
	data->up[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->up[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/up2.png");
	if (!temp_img)
		return (-1);
	data->up[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->up[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_up2(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/up3.png");
	if (!temp_img)
		return (-1);
	data->up[2] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->up[2])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/up4.png");
	if (!temp_img)
		return (-1);
	data->up[3] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->up[3])
		return (-1);
	mlx_delete_texture(temp_img);
	data->up[4] = NULL;
	return (0);
}

int	player_image_down(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/down1.png");
	if (!temp_img)
		return (-1);
	data->down[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->down[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/down2.png");
	if (!temp_img)
		return (-1);
	data->down[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->down[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_down2(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/down3.png");
	if (!temp_img)
		return (-1);
	data->down[2] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->down[2])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/down4.png");
	if (!temp_img)
		return (-1);
	data->down[3] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->down[3])
		return (-1);
	mlx_delete_texture(temp_img);
	data->down[4] = NULL;
	return (0);
}

int	player_image_left(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/right1.png");
	if (!temp_img)
		return (-1);
	data->right[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->right[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/right2.png");
	if (!temp_img)
		return (-1);
	data->right[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->right[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_left2(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/right3.png");
	if (!temp_img)
		return (-1);
	data->right[2] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->right[2])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/right4.png");
	if (!temp_img)
		return (-1);
	data->right[3] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->right[3])
		return (-1);
	mlx_delete_texture(temp_img);
	data->left[4] = NULL;
	return (0);
}

int	player_image_right(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/left1.png");
	if (!temp_img)
		return (-1);
	data->left[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->left[0])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/left2.png");
	if (!temp_img)
		return (-1);
	data->left[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->left[1])
		return (-1);
	mlx_delete_texture(temp_img);
	return (0);
}

int	player_image_right2(t_data *data)

{
	mlx_texture_t	*temp_img;

	temp_img = mlx_load_png("./assets/player1/left3.png");
	if (!temp_img)
		return (-1);
	data->left[2] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->left[2])
		return (-1);
	mlx_delete_texture(temp_img);
	temp_img = mlx_load_png("./assets/player1/left4.png");
	if (!temp_img)
		return (-1);
	data->left[3] = mlx_texture_to_image(data->mlx_ptr, temp_img);
	if (!data->left[3])
		return (-1);
	mlx_delete_texture(temp_img);
	data->right[4] = NULL;
	return (0);
}
