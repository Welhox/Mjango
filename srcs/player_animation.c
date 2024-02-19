/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:20:43 by clundber          #+#    #+#             */
/*   Updated: 2024/02/19 16:28:23 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animation_down(t_data *data)

{
	if (data->down[0]->instances->enabled == 1
		|| data->down[1]->instances->enabled == 1)
	{
		if (data->down[0]->instances->enabled == 1)
		{
			data->down[0]->instances->enabled = 0;
			data->down[1]->instances->enabled = 1;
		}
		else
		{
			data->down[0]->instances->enabled = 1;
			data->down[1]->instances->enabled = 0;
		}
	}
	else
	{
		player_image(data);
		data->down[0]->instances->enabled = 1;
	}
}

void	animation_up(t_data *data)

{
	if (data->up[0]->instances->enabled == 1
		|| data->up[1]->instances->enabled == 1)
	{
		if (data->up[0]->instances->enabled == 1)
		{
			data->up[0]->instances->enabled = 0;
			data->up[1]->instances->enabled = 1;
		}
		else
		{
			data->up[0]->instances->enabled = 1;
			data->up[1]->instances->enabled = 0;
		}
	}
	else
	{
		player_image(data);
		data->up[0]->instances->enabled = 1;
	}
}

void	animation_left(t_data *data)

{
	if (data->left[0]->instances->enabled == 1
		|| data->left[1]->instances->enabled == 1)
	{
		if (data->left[0]->instances->enabled == 1)
		{
			data->left[0]->instances->enabled = 0;
			data->left[1]->instances->enabled = 1;
		}
		else
		{
			data->left[0]->instances->enabled = 1;
			data->left[1]->instances->enabled = 0;
		}
	}
	else
	{
		player_image(data);
		data->left[0]->instances->enabled = 1;
	}
}

void	animation_right(t_data *data)

{
	if (data->right[0]->instances->enabled == 1
		|| data->right[1]->instances->enabled == 1)
	{
		if (data->right[0]->instances->enabled == 1)
		{
			data->right[0]->instances->enabled = 0;
			data->right[1]->instances->enabled = 1;
		}
		else
		{
			data->right[0]->instances->enabled = 1;
			data->right[1]->instances->enabled = 0;
		}
	}
	else
	{
		player_image(data);
		data->right[0]->instances->enabled = 1;
	}
}