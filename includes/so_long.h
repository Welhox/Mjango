/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:25:50 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 16:11:13 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TX_SIZE 64

typedef struct s_data
{
	int			width;
	int			height;
	int			c_nbr;
	int			p_nbr;
	int			c_found;
	int			e_nbr;
	int			pos_x;
	int			pos_y;
	int			mvt_count;
	char		**map;
	t_bool		exit_ok;
	t_bool		error;
	void		*mlx_ptr;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collect;
	mlx_image_t	*cave;
	mlx_image_t	*up[3];
	mlx_image_t	*down[3];
	mlx_image_t	*left[3];
	mlx_image_t	*right[3];
}	t_data;

// argument checking / initialisation //

void	window_size(t_data *data);
void	init_struct(t_data *data);
void	argcheck(char **argv, int argc);

//	map functions	//

void	check_map(t_data *data);
void	get_map(t_data *data, char **argv);
void	map_size(t_data *data);
void	map_borders(t_data *data);
void	map_icons(t_data *data);
int		char_check(char c, char *str);
char	**array_copy(char **array);
void	check_path(t_data *data);
void	reader(int rd, int fd, char *buffer, char **map_str);
char	*map_append(char *map_str, char *buffer);
void	check_nline(t_data *data, char *map_str);
void	flood_fill(int pos_y, int pos_x, char **map, t_data *data);

// player functions //

void	player_up(t_data *data);
void	player_down(t_data *data);
void	player_left(t_data *data);
void	player_right(t_data *data);
void	player_action(t_data *data);
void	animation_down(t_data *data);
void	animation_up(t_data *data);
void	animation_left(t_data *data);
void	animation_right(t_data *data);

// rendering //

void	map_render(t_data *data);
void	player_render(t_data *data);
int		map_image_assets(t_data *data);
int		map_image_terrain(t_data *data);
void	image_init(t_data *data);
int		player_image_up(t_data *data);
int		player_image_down(t_data *data);
int		player_image_left(t_data *data);
int		player_image_right(t_data *data);
void	player_image(t_data *data);
void	image_render(t_data *data, int y, int x);

// MLX //

void	termination(void *param);
void	error_func(char *err_msg);

#endif