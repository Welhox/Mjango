/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:25:43 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 12:23:31 by clundber         ###   ########.fr       */
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

void	flood_fill(int pos_y, int pos_x, char **map, t_data *data)

{
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == '2')
		return ;
	if (map[pos_y][pos_x] == 'E')
		data->exit_ok = true;
	if (map[pos_y][pos_x] == 'C')
		data->c_found++;
	map[pos_y][pos_x] = '2';
	flood_fill(pos_y +1, pos_x, map, data);
	flood_fill(pos_y -1, pos_x, map, data);
	flood_fill(pos_y, pos_x +1, map, data);
	flood_fill(pos_y, pos_x -1, map, data);
	return ;
}

void	check_path(t_data *data)

{
	char	**temp_map;

	temp_map = array_copy(data->map);
	if (!temp_map)
	{
		ft_arrfree(data->map);
		error_func("map copy malloc failed\n");
	}
	flood_fill(data->pos_y, data->pos_x, temp_map, data);
	if (data->exit_ok == false || data->c_nbr != data->c_found)
		data->error = true;
	ft_arrfree(temp_map);
	data->exit_ok = false;
	data->c_found = 0;
}
