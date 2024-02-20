/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:50:11 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 15:39:15 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_borders(t_data *data)

{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
		if (data->map[y][0] != '1' || data->map[y][x -1] != '1')
			data->error = true;
		y++;
	}
	x = 0;
	while (data->map[0][x])
	{
		if (data->map[0][x] != '1')
			data->error = true;
		if (data->map[y -1][x] != '1')
			data->error = true;
		x++;
	}
}

void	map_size(t_data *data)
{
	int	y;
	int	x;
	int	width;

	width = 0;
	x = 0;
	y = 0;
	while (data->map[0][width])
		width++;
	while (data->map[y])
	{
		while (data->map[y][x])
			x++;
		if (x != width)
			data->error = true;
		x = 0;
		y++;
	}
	if (y < 3 || width < 3)
		data->error = true;
	data->height = y * TX_SIZE;
	data->width = width * TX_SIZE;
}

int	char_check(char c, char *str)

{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	map_icons(t_data *data)

{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (char_check(data->map[y][x], "01CEP") == 0)
				data->error = true;
			if (data->map[y][x] == 'P')
			{
				data->p_nbr++;
				data->pos_y = y;
				data->pos_x = x;
			}
			if (data->map[y][x] == 'C')
				data->c_nbr++;
			if (data->map[y][x] == 'E')
				data->e_nbr++;
			x++;
		}
		y++;
	}
}

void	check_map(t_data *data)

{
	map_size(data);
	if (data->error == true)
		error_func("map format wrong\n");
	map_borders(data);
	if (data->error == true)
		error_func("map borders faulty\n");
	map_icons(data);
	if (data->error == true)
		error_func("map icons not as expected\n");
	if (data->p_nbr != 1 || data->c_nbr < 1 || data->e_nbr != 1)
		data->error = true;
	if (data->error == true)
		error_func("incorrect ammount of characters in map\n");
	check_path(data);
	if (data->error == true)
		error_func("No valid path available\n");
}
