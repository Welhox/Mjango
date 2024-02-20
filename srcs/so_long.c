/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 21:42:44 by clundber         ###   ########.fr       */
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
		mlx_terminate(data->mlx_ptr);
		exit(1);
	}
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
	player_render(&data);
	mlx_key_hook(data.mlx_ptr, &key_input, &data);
	mlx_close_hook(data.mlx_ptr, &termination, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
	ft_arrfree(data.map);
	ft_printf("Great sucess\n");
}

/* • open, close, read, write,
malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm compiler option,
man man 3 math)
• All functions of the MiniLibX */