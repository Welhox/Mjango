/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:25:50 by clundber          #+#    #+#             */
/*   Updated: 2024/02/09 19:49:31 by clundber         ###   ########.fr       */
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
int	map_height;
int	collectables;
t_bool error;
int	p_nbr;
int	c_nbr;
int	c_found;
int e_nbr;
int	p_pos[2];
t_bool exit_found;

} t_map;

void	error_func(t_map *smap, char *err_msg);
char	*map_append(char *map_str, char *buffer);
void	init_struct(t_map  *smap);

//	map functions	//
void	check_map(t_map *smap);
void	get_map(t_map *lsl, char **argv);
void	map_size(t_map *smap);
void	map_borders(t_map *smap);
void	map_icons(t_map *smap);
int	char_check(char c);
char **array_copy(char **array);
void	check_path(t_map *smap);

#endif