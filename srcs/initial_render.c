/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:53:30 by clundber          #+#    #+#             */
/*   Updated: 2024/02/16 17:20:07 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_render(t_data *data)

{
	int	x = 0;
	int y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_image_to_window(data->mlx_ptr, data->wall_img, (x * TEXTURE_SIZE), (y * TEXTURE_SIZE));	
			else
				mlx_image_to_window(data->mlx_ptr, data->grass_img, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			if (data->map[y][x] == 'C')
				mlx_image_to_window(data->mlx_ptr, data->collectable, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else if (data->map[y][x] == 'E')
			{
				mlx_image_to_window(data->mlx_ptr, data->cave, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
				data->cave->instances->enabled = 0;
			}
			x++;
		}
		y++;
	}
}

void	player_render(t_data *data)

{
	mlx_image_to_window(data->mlx_ptr, data->down[0], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->down[1], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->down[1]->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->up[0], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->up[0]->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->up[1], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->up[1]->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->left[0], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->left[0]->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->left[1], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->left[1]->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->right[0], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->right[0]->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->right[1], data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->right[1]->instances->enabled = 0;
}

void	image_init(t_data *data)

{
	mlx_texture_t *wall = mlx_load_png("./assets/rock_wall.png");
	data->wall_img = mlx_texture_to_image(data->mlx_ptr, wall);
	mlx_resize_image(data->wall_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *grass = mlx_load_png("./assets/grass.png");
	data->grass_img = mlx_texture_to_image(data->mlx_ptr, grass);
	mlx_resize_image(data->grass_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *temp_img = mlx_load_png("./assets/collectable.png");
	data->collectable = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img = mlx_load_png("./assets/cave.png");
	data->cave = mlx_texture_to_image(data->mlx_ptr, temp_img);


	temp_img = mlx_load_png("./assets/player/player_up1.png");
	data->up[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img = mlx_load_png("./assets/player/player_up2.png");
	data->up[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img = mlx_load_png("./assets/player/player_down1.png"); 
	data->down[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img = mlx_load_png("./assets/player/player_down2.png");
	data->down[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img = mlx_load_png("./assets/player/player_left1.png"); 
	data->left[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img = mlx_load_png("./assets/player/player_left2.png");
	data->left[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img =  mlx_load_png("./assets/player/player_right1.png");
	data->right[0] = mlx_texture_to_image(data->mlx_ptr, temp_img);

	temp_img =  mlx_load_png("./assets/player/player_right2.png");
	data->right[1] = mlx_texture_to_image(data->mlx_ptr, temp_img);


/* 	mlx_texture_t *p_up1 = mlx_load_png("./assets/player/player_up1.png");
	data->p_up1_img = mlx_texture_to_image(data->mlx_ptr, p_up1);
	mlx_resize_image(data->p_up1_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_up2 = mlx_load_png("./assets/player/player_up2.png");
	data->p_up2_img = mlx_texture_to_image(data->mlx_ptr, p_up2);
	mlx_resize_image(data->p_up2_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_down1 = mlx_load_png("./assets/player/player_down1.png");
	data->p_down1_img = mlx_texture_to_image(data->mlx_ptr, p_down1);
	mlx_resize_image(data->p_down1_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_down2 = mlx_load_png("./assets/player/player_down2.png");
	data->p_down2_img = mlx_texture_to_image(data->mlx_ptr, p_down2);
	mlx_resize_image(data->p_down2_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_left1 = mlx_load_png("./assets/player/player_left1.png");
	data->p_left1_img = mlx_texture_to_image(data->mlx_ptr, p_left1);
	mlx_resize_image(data->p_left1_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_left2 = mlx_load_png("./assets/player/player_left2.png");
	data->p_left2_img = mlx_texture_to_image(data->mlx_ptr, p_left2);
	mlx_resize_image(data->p_left2_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_right1 = mlx_load_png("./assets/player/player_right1.png");
	data->p_right1_img = mlx_texture_to_image(data->mlx_ptr, p_right1);
	mlx_resize_image(data->p_right1_img, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_texture_t *p_right2 = mlx_load_png("./assets/player/player_right2.png");
	data->p_right2_img = mlx_texture_to_image(data->mlx_ptr, p_right2);
	mlx_resize_image(data->p_right2_img, TEXTURE_SIZE, TEXTURE_SIZE); */
}