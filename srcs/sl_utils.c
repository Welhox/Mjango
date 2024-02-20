/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:49:23 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 19:36:25 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	termination(void *param)

{
	t_data	*data;

	data = param;
	ft_arrfree(data->map);
	mlx_terminate(data->mlx_ptr);
	exit(1);
}

void	victory(t_data *data)

{
	ft_arrfree(data->map);
	mlx_terminate(data->mlx_ptr);
	ft_printf("********************\n");
	ft_printf("********************\n");
	ft_printf("*****YOU WIN!!!*****\n");
	ft_printf("********************\n");
	ft_printf("********************\n");
	exit(0);
}

void	window_size(t_data *data)

{
	int32_t	s_width;
	int32_t	s_height;	

	mlx_get_monitor_size(0, &s_width, &s_height);
	if (data->width > s_width || data->height > s_height)
	{
		mlx_terminate(data->mlx_ptr);
		ft_arrfree(data->map);
		error_func("Map too big for screen\n");
	}
}

void	error_func(char *err_msg)

{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

void	argcheck(char **argv, int argc)

{
	int	i;

	i = 0;
	if (argc != 2)
		error_func("incorrect ammount of arguments\n");
	while (argv[1] && argv[1][i])
		i++;
	if (i < 5)
		error_func("incorrect map name\n");
	if (i > 4)
	{
		if (argv[1][i -1] != 'r' || argv[1][i -2] != 'e' ||
		argv[1][i -3] != 'b' || argv[1][i -4] != '.')
			error_func("incorrect map name\n");
	}
}
