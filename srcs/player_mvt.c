/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:40:22 by clundber          #+#    #+#             */
/*   Updated: 2024/02/16 17:18:57 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_up(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y - 1][data->player_x] == '1')
		return ;
	if (data->map[data->player_y - 1][data->player_x] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{	
			if(data->collectable->instances[i].x == data->player_x * TEXTURE_SIZE&&
			data->collectable->instances[i].y == (data->player_y - 1) * TEXTURE_SIZE)
			{	
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y - 1][data->player_x] = '0';
			}
			i++;
		}
	}
	data->down[0]->instances->y -= pixels;
	data->down[1]->instances->y -= pixels;
	data->up[0]->instances->y -= pixels;
	data->up[1]->instances->y -= pixels;
	data->left[0]->instances->y -= pixels;
	data->left[1]->instances->y -= pixels;
	data->right[0]->instances->y -= pixels;
	data->right[1]->instances->y -= pixels;
	data->player_y--;
	data->mvt_count++;
}

void	player_down(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y + 1][data->player_x] == '1')
		return ;
	if (data->map[data->player_y + 1][data->player_x] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{	
			if(data->collectable->instances[i].x == data->player_x * TEXTURE_SIZE &&
			data->collectable->instances[i].y == (data->player_y + 1) * TEXTURE_SIZE)
			{
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y + 1][data->player_x] = '0';
			}
			i++;
		}
	}
	data->down[0]->instances->y += pixels;
	data->down[1]->instances->y += pixels;
	data->up[0]->instances->y += pixels;
	data->up[1]->instances->y += pixels;
	data->left[0]->instances->y += pixels;
	data->left[1]->instances->y += pixels;
	data->right[0]->instances->y += pixels;
	data->right[1]->instances->y += pixels;
	data->player_y++;
	data->mvt_count++;
}

void	player_left(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y][data->player_x - 1] == '1')
		return ;
	if (data->map[data->player_y][data->player_x - 1] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{	
			if(data->collectable->instances[i].x == (data->player_x - 1) * TEXTURE_SIZE &&
			data->collectable->instances[i].y == data->player_y * TEXTURE_SIZE)
			{
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y][data->player_x - 1] = '0';
			}
			i++;
		}
	}
	data->down[0]->instances->x -= pixels;
	data->down[1]->instances->x -= pixels;
	data->up[0]->instances->x -= pixels;
	data->up[1]->instances->x -= pixels;
	data->left[0]->instances->x -= pixels;
	data->left[1]->instances->x -= pixels;
	data->right[0]->instances->x -= pixels;
	data->right[1]->instances->x -= pixels;
	data->player_x--;
	data->mvt_count++;
}

void	player_right(t_data *data, int pixels)

{
	int	i;

	i = 0;
	if (data->map[data->player_y][data->player_x + 1] == '1')
		return ;
	if (data->map[data->player_y][data->player_x + 1] == 'C')
	{
		data->c_found++;
		while (i < data->c_nbr)
		{
			if(data->collectable->instances[i].x == (data->player_x + 1) * TEXTURE_SIZE &&
			data->collectable->instances[i].y == data->player_y * TEXTURE_SIZE)
			{
				data->collectable->instances[i].enabled = 0;
				data->map[data->player_y][data->player_x + 1] = '0';
			}
			i++;
		}
	}
	data->down[0]->instances->x += pixels;
	data->down[1]->instances->x += pixels;
	data->up[0]->instances->x += pixels;
	data->up[1]->instances->x += pixels;
	data->left[0]->instances->x += pixels;
	data->left[1]->instances->x += pixels;
	data->right[0]->instances->x += pixels;
	data->right[1]->instances->x += pixels;
	data->player_x++;
	data->mvt_count++;
}