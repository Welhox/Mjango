/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:50:11 by clundber          #+#    #+#             */
/*   Updated: 2024/02/12 13:40:46 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_borders(t_map *smap)

{
	int	x;
	int	y;

	y = 0;
	while (smap->map[y])
	{
		x = 0;
		while (smap->map[y][x])
			x++;
		if (smap->map[y][0] != '1' || smap->map[y][x -1] != '1')
			smap->error = true;
		y++;
	}
	x = 0;
	while (smap->map[0][x])
	{
		if (smap->map[0][x] != '1')
			smap->error = true;
		if (smap->map[y -1][x] != '1')
			smap->error = true;
		x++;
	}
}

void	map_size(t_map *smap)
{
	int	y;
	int	x;
	int	width;

	width = 0;
	x = 0;
	y = 0;
	while (smap->map[0][width])
		width++;
	while (smap->map[y])
	{
		while (smap->map[y][x])
			x++;
		if (x != width)
			smap->error = true;
		x = 0;
		y++;
	}
	if (y < 3 || width < 3)
		smap->error = true;
	smap->map_height = y;
	smap->map_width = width;
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

void	map_icons(t_map *smap)

{
	int	x;
	int	y;

	y = 0;
	while (smap->map[y])
	{
		x = 0;
		while (smap->map[y][x])
		{
			if (char_check(smap->map[y][x], "01CEP") == 0)
				smap->error = true;
			if (smap->map[y][x] == 'P')
			{
				smap->p_nbr++;
				smap->p_pos[0] = y;
				smap->p_pos[1] = x;
			}
			if (smap->map[y][x] == 'C')
				smap->c_nbr++;
			if (smap->map[y][x] == 'E')
				smap->e_nbr++;
			x++;
		}
		y++;
	}
}

void	check_map(t_map *smap)

{
	map_size(smap);
	if (smap->error == true)
		error_func("map format wrong\n");
	map_borders(smap);
	if (smap->error == true)
		error_func("map borders faulty\n");
	map_icons(smap);
	if (smap->error == true)
		error_func("map icons not as expected\n");
	if (smap->p_nbr != 1 || smap->c_nbr < 1 || smap->e_nbr != 1)
		smap->error = true;
	if (smap->error == true)
		error_func("incorrect ammount of characters in map\n");
	check_path(smap);
	if (smap->error == true)
		error_func("No valid path available\n");
}
