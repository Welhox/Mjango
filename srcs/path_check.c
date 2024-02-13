/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:25:43 by clundber          #+#    #+#             */
/*   Updated: 2024/02/13 15:14:32 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**array_copy(char **array)

{
	char	**new_array;
	int		i;

	i = 0;
	new_array = NULL;
	while (array[i])
		i++;
	new_array = malloc(sizeof(char *) * (i +1));
	if (!new_array)
		return (0);
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			ft_arrfree(new_array);
			return (0);
		}
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

void	flood_fill(int pos_y, int pos_x, char **map, t_map *smap)

{
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == '2')
		return ;
	if (map[pos_y][pos_x] == 'E')
		smap->exit_found = true;
	if (map[pos_y][pos_x] == 'C')
		smap->c_found++;
	map[pos_y][pos_x] = '2';
	flood_fill(pos_y +1, pos_x, map, smap);
	flood_fill(pos_y -1, pos_x, map, smap);
	flood_fill(pos_y, pos_x +1, map, smap);
	flood_fill(pos_y, pos_x -1, map, smap);
	return ;
}

void	check_path(t_map *smap)

{
	char	**temp_map;

	temp_map = array_copy(smap->map);
	if (!temp_map)
	{
		ft_arrfree(smap->map);
		error_func("map copy malloc failed\n");
	}
	flood_fill(smap->p_pos[0], smap->p_pos[1], temp_map, smap);
	if (smap->exit_found == false || smap->c_nbr != smap->c_found)
		smap->error = true;
	ft_arrfree(temp_map);
}
