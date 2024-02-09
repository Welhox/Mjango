/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:25:43 by clundber          #+#    #+#             */
/*   Updated: 2024/02/09 18:57:28 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **array_copy(char **array)

{
	char **new_array;
	int		i;

	i = 0;
	new_array = NULL;
	while(array[i])
		i++;
	new_array = malloc(sizeof(char *) * i);
	if (!new_array)
		return(0);
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			ft_arrfree(new_array);
			return(0);
		}	
		i++;
	}
	new_array[i] = NULL;
	return(new_array);
}

void	check_path(t_map *smap)

{
	char **temp_map;

	temp_map = array_copy(smap->map);
	if (!temp_map)
	{
		exit(1);
		// freeing and exiting correctly etc after malloc failure
	}
	
}