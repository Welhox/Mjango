/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/19 16:35:30 by clundber         ###   ########.fr       */
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
	data->height = smap->map_height * TX_SIZE;
	data->width = smap->map_width * TX_SIZE;
	data->map = array_copy(smap->map);
	data->pos_x = smap->p_pos[0];
	data->pos_y = smap->p_pos[1];
	data->mvt_count = 0;
	data->c_nbr = smap->c_nbr;
	data->c_found = 0;
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
	data_init(&data, &smap);
	data.mlx_ptr = mlx_init(data.width, data.height, "so_long", false);
	if (!data.mlx_ptr)
		error_func("some error\n");
			//also need freeing func

	image_init(&data);
	map_render(&data);

	// player rendering
	player_render(&data);
	//mlx_hook
	mlx_key_hook(data.mlx_ptr, &key_input, &data);
	
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);

	ft_arrfree(data.map);
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