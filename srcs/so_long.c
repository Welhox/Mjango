/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/16 17:20:08 by clundber         ###   ########.fr       */
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

void	key_input(mlx_key_data_t keydata, void *param)

{
	t_data *data;

	data = param;
	if(keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_down(data, 64);
		if (data->down[0]->instances->enabled == 1 || data->down[1]->instances->enabled == 1)
		{
			if(data->down[0]->instances->enabled == 1)
			{
				data->down[0]->instances->enabled = 0;
				data->down[1]->instances->enabled = 1;
			}
			else
			{
				data->down[0]->instances->enabled = 1;
				data->down[1]->instances->enabled = 0;

			}
		}
		else
		{
			player_image(data);
			data->down[0]->instances->enabled = 1;
		}
	}
	if(keydata.key == MLX_KEY_UP &&(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_up(data, 64);
		player_image(data);
		data->up[0]->instances->enabled = 1;
	}
	if(keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_left(data, 64);
		player_image(data);
		data->left[0]->instances->enabled = 1;
	}
	if(keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		player_right(data, 64);
		player_image(data);
		data->right[0]->instances->enabled = 1;
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
	map_render(&data);

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