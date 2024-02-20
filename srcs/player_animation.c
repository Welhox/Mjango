/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:20:43 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 22:56:23 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animation_down(t_data *data)

{
	static unsigned int	i;

	if (!i)
		i = 0;
	player_image(data);
	data->down[i % 4]->instances->enabled = 1;
	i++;
}

void	animation_up(t_data *data)

{
	static unsigned int	i;

	if (!i)
		i = 0;
	player_image(data);
	data->up[i % 4]->instances->enabled = 1;
	i++;
}

void	animation_left(t_data *data)

{
	static unsigned int	i;

	if (!i)
		i = 0;
	player_image(data);
	data->left[i % 4]->instances->enabled = 1;
	i++;
}

void	animation_right(t_data *data)

{
	static unsigned int	i;

	if (!i)
		i = 0;
	player_image(data);
	data->right[i % 4]->instances->enabled = 1;
	i++;
}
