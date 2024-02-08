/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:25:50 by clundber          #+#    #+#             */
/*   Updated: 2024/02/07 15:23:09 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

typedef struct s_struct
{
char **map;
int	map_width;
int	map_depth;
} t_struct;

void	error_func(t_struct *lstruct, char *err_msg);
void	check_map(t_struct *lstruct);
void	get_map(t_struct *lstruct, char **argv);

#endif