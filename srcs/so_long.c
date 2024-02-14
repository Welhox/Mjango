/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/14 17:58:07 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_func(char *err_msg)

{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

void	init_struct(t_map *smap)

{
	smap->map = NULL;
	smap->map_height = 0;
	smap->map_width = 0;
	smap->error = false;
	smap->p_nbr = 0;
	smap->c_nbr = 0;
	smap->c_found = 0;
	smap->e_nbr = 0;
	smap->p_pos[0] = 0;
	smap->p_pos[1] = 0;
	smap->exit_found = false;
}

void	map_name(char **argv)

{
	int	i;

	i = 0;
	while (argv[1] && argv[1][i])
		i++;
	if (i < 5)
		error_func("incorrect map name\n");
	if (i > 4)
	{
		if (argv[1][i -1] != 'r' || argv[1][i -2] != 'e' ||
		argv[1][i -3] != 'b' || argv[1][i -4] != '.')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
}

void	data_init(t_data *data, t_map *smap)

{
	data->mlx_ptr = NULL;
	data->height = smap->map_height * TEXTURE_SIZE;
	data->width = smap->map_width * TEXTURE_SIZE;
	data->map = array_copy(smap->map);
	data->player_x = smap->p_pos[0];
	data->player_y = smap->p_pos[1];
	data->mvt_count = 0;
	data->c_nbr = smap->c_nbr;
	data->c_found = 0;
	data->exit_ok = false;
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

	mlx_texture_t *p_up1 = mlx_load_png("./assets/player/player_up1.png");
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
	mlx_resize_image(data->p_right2_img, TEXTURE_SIZE, TEXTURE_SIZE);
}

void	map_render(t_map *smap, t_data *data)

{
	int	x = 0;
	int y = 0;
	while (smap->map[y])
	{
		x = 0;
		while (smap->map[y][x])
		{
			if (smap->map[y][x] == '1')
				mlx_image_to_window(data->mlx_ptr, data->wall_img, (x * TEXTURE_SIZE), (y * TEXTURE_SIZE));	
			else
				mlx_image_to_window(data->mlx_ptr, data->grass_img, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			if (smap->map[y][x] == 'C')
				mlx_image_to_window(data->mlx_ptr, data->collectable, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else if (smap->map[y][x] == 'E')
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
	mlx_image_to_window(data->mlx_ptr, data->p_down1_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	mlx_image_to_window(data->mlx_ptr, data->p_down2_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_down2_img->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->p_up1_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_up1_img->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->p_up2_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_up2_img->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->p_left1_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_left1_img->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->p_left2_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_left2_img->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->p_right1_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_right1_img->instances->enabled = 0;
	mlx_image_to_window(data->mlx_ptr, data->p_right2_img, data->player_x * TEXTURE_SIZE, data->player_y * TEXTURE_SIZE);
	data->p_right2_img->instances->enabled = 0;
}

void	player_image(t_data *data)

{
	data->p_down1_img->instances->enabled = 0;
	data->p_down2_img->instances->enabled = 0;
	data->p_up1_img->instances->enabled = 0;
	data->p_up2_img->instances->enabled = 0;
	data->p_left1_img->instances->enabled = 0;
	data->p_left2_img->instances->enabled = 0;
	data->p_right1_img->instances->enabled = 0;
	data->p_right2_img->instances->enabled = 0;
}

void	player_up(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y - 1][data->player_x] == '1')
		return ;
	if (data->map[data->player_y - 1][data->player_x] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{	
			if(data->collectable->instances[i].x == data->player_x * TEXTURE_SIZE&&
			data->collectable->instances[i].y == (data->player_y - 1) * TEXTURE_SIZE)
			{	
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y - 1][data->player_x] = '0';
			}
			i++;
		}
	}
	data->p_down1_img->instances->y -= pixels;
	data->p_down2_img->instances->y -= pixels;
	data->p_up1_img->instances->y -= pixels;
	data->p_up2_img->instances->y -= pixels;
	data->p_left1_img->instances->y -= pixels;
	data->p_left2_img->instances->y -= pixels;
	data->p_right1_img->instances->y -= pixels;
	data->p_right2_img->instances->y -= pixels;
	data->player_y--;
	data->mvt_count++;
}

void	player_down(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y + 1][data->player_x] == '1')
		return ;
	if (data->map[data->player_y + 1][data->player_x] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{	
			if(data->collectable->instances[i].x == data->player_x * TEXTURE_SIZE &&
			data->collectable->instances[i].y == (data->player_y + 1) * TEXTURE_SIZE)
			{
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y + 1][data->player_x] = '0';
			}
			i++;
		}
	}
	data->p_down1_img->instances->y += pixels;
	data->p_down2_img->instances->y += pixels;
	data->p_up1_img->instances->y += pixels;
	data->p_up2_img->instances->y += pixels;
	data->p_left1_img->instances->y += pixels;
	data->p_left2_img->instances->y += pixels;
	data->p_right1_img->instances->y += pixels;
	data->p_right2_img->instances->y += pixels;
	data->player_y++;
	data->mvt_count++;
}

void	player_left(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y][data->player_x - 1] == '1')
		return ;
	if (data->map[data->player_y][data->player_x - 1] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{	
			if(data->collectable->instances[i].x == (data->player_x - 1) * TEXTURE_SIZE &&
			data->collectable->instances[i].y == data->player_y * TEXTURE_SIZE)
			{
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y][data->player_x - 1] = '0';
			}
			i++;
		}
	}
	data->p_down1_img->instances->x -= pixels;
	data->p_down2_img->instances->x -= pixels;
	data->p_up1_img->instances->x -= pixels;
	data->p_up2_img->instances->x -= pixels;
	data->p_left1_img->instances->x -= pixels;
	data->p_left2_img->instances->x -= pixels;
	data->p_right1_img->instances->x -= pixels;
	data->p_right2_img->instances->x -= pixels;
	data->player_x--;
	data->mvt_count++;
}

void	player_right(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y][data->player_x + 1] == '1')
		return ;
	if (data->map[data->player_y][data->player_x + 1] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{
			if(data->collectable->instances[i].x == (data->player_x + 1) * TEXTURE_SIZE &&
			data->collectable->instances[i].y == data->player_y * TEXTURE_SIZE)
			{
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y][data->player_x + 1] = '0';
			}
			i++;
		}
	}
	data->p_down1_img->instances->x += pixels;
	data->p_down2_img->instances->x += pixels;
	data->p_up1_img->instances->x += pixels;
	data->p_up2_img->instances->x += pixels;
	data->p_left1_img->instances->x += pixels;
	data->p_left2_img->instances->x += pixels;
	data->p_right1_img->instances->x += pixels;
	data->p_right2_img->instances->x += pixels;
	data->player_x++;
	data->mvt_count++;
}

void	key_input(mlx_key_data_t keydata, void *param)

{
	t_data *data;

	data = param;
	if(keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_down(data, 64);
		if (data->p_down1_img->instances->enabled == 1 || data->p_down2_img->instances->enabled == 1)
		{	
			if(data->p_down1_img->instances->enabled == 1)
			{
				data->p_down1_img->instances->enabled = 0;
				data->p_down2_img->instances->enabled = 1;
			}
			else
			{
				data->p_down1_img->instances->enabled = 1;
				data->p_down2_img->instances->enabled = 0;

			}
		}
		else
		{
			player_image(data);
			data->p_down1_img->instances->enabled = 1;
		}
	}
	if(keydata.key == MLX_KEY_UP &&(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_up(data, 64);
		player_image(data);
		data->p_up1_img->instances->enabled = 1;
	}
	if(keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_left(data, 64);
		player_image(data);
		data->p_left1_img->instances->enabled = 1;
	}
	if(keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_right(data, 64);
		player_image(data);
		data->p_right1_img->instances->enabled = 1;
	}
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_printf("esc\n");		//needs exit function;
	if(data->c_found == data->c_nbr)
	{
		data->cave->instances->enabled = 1;
		data->exit_ok = true;
	}
	if (data->map[data->player_y][data->player_x] == 'E' && data->exit_ok == true)
	{
		ft_printf("YOU WIN!!!!\n");
		exit (1);
	}
}

int	main(int argc, char *argv[])

{
	t_map	smap;
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	init_struct(&smap);
	map_name(argv);
	get_map(&smap, argv);
	if (!smap.map)
		error_func("malloc fail\n");
	check_map(&smap);
	//start of MLX shenanigans

	// data initialisation
	data_init(&data, &smap);
	data.mlx_ptr = mlx_init(data.width, data.height, "so_long", false);
	if (!data.mlx_ptr)
		error_func("some error\n");
			//also need freeing func

	image_init(&data);
			//also need freeing func
	map_render(&smap, &data);

	// player rendering
	player_render(&data);
	//mlx_hook
	mlx_key_hook(data.mlx_ptr, &key_input, &data);
	
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);


	ft_arrfree(smap.map);
	ft_printf("Great sucess\n");
}

/* • open, close, read, write,
malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm compiler option,
man man 3 math)
• All functions of the MiniLibX */