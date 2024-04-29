/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_hole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:09:48 by clundber          #+#    #+#             */
/*   Updated: 2024/02/23 10:57:06 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_image(t_data *data)

{
	int				i;
	mlx_texture_t	*temp_img;
	char			*path;
	char			*number;

	path = NULL;
	i = -1;
	while (++i < 20)
	{
		number = ft_itoa(i +1);
		path = ft_trijoin("./assets/Gravity/Gravity", number, ".png");
		if (!path || !number)
			return (-1);
		free (number);
		temp_img = mlx_load_png(path);
		free (path);
		if (!temp_img)
			return (-1);
		data->exit[i] = mlx_texture_to_image(data->mlx_ptr, temp_img);
		if (!data->exit[i])
			return (-1);
		mlx_delete_texture(temp_img);
	}
	data->exit[20] = NULL;
	return (0);
}

void	exit_animation(void *param)

{
	t_data		*data;
	static int	i;
	int			k;

	data = param;
	if (data->exit_ok == false)
		return ;
	k = 0;
	if (!i)
		i = 0;
	while (k < 20)
		data->exit[k++]->instances->enabled = 0;
	data->exit[i / 10]->instances->enabled = 1;
	i++;
	if (i >= 200)
		i = 0;
}
