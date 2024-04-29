/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/23 11:14:51 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_data *data)

{
	data->width = 0;
	data->height = 0;
	data->c_nbr = 0;
	data->p_nbr = 0;
	data->c_found = 0;
	data->e_nbr = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->mvt_count = 0;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->exit_ok = false;
	data->error = false;
}

void	key_input(mlx_key_data_t keydata, void *param)

{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		player_down(data);
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		player_up(data);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		player_left(data);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		player_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_arrfree(data->map);
		mlx_close_window(data->mlx_ptr);
		mlx_terminate(data->mlx_ptr);
		exit(1);
	}
}

void	collect_animation(void *param)

{
	t_data		*data;
	static int	i;
	int			k;

	k = 0;
	if (!i)
		i = 0;
	data = param;
	while (k < data->c_nbr)
	{
		data->collect[0]->instances[k].enabled = 0;
		data->collect[1]->instances[k].enabled = 0;
		data->collect[2]->instances[k].enabled = 0;
		data->collect[3]->instances[k].enabled = 0;
		data->collect[i / 10]->instances[k].enabled = 1;
		k++;
	}
	i++;
	if (i >= 40)
		i = 0;
}

int	main(int argc, char *argv[])

{
	t_data	data;

	init_struct(&data);
	argcheck(argv, argc);
	get_map(&data, argv);
	if (!data.map)
		error_func("malloc fail\n");
	check_map(&data);
	data.mlx_ptr = mlx_init(data.width, data.height, "so_long", false);
	if (!data.mlx_ptr)
	{
		ft_arrfree(data.map);
		error_func("MLX failed to initialise\n");
	}
	window_size(&data);
	image_init(&data);
	map_render(&data);
	player_render1(&data);
	mlx_key_hook(data.mlx_ptr, &key_input, &data);
	mlx_close_hook(data.mlx_ptr, &termination, &data);
	mlx_loop_hook(data.mlx_ptr, &collect_animation, &data);
	mlx_loop_hook(data.mlx_ptr, &exit_animation, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
	ft_arrfree(data.map);
}
