/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:25:50 by clundber          #+#    #+#             */
/*   Updated: 2024/02/19 16:29:42 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
typedef struct s_struct
{
	char	**map;
	int		map_width;
	int		map_height;
	int		collectables;
	t_bool	error;
	int		p_nbr;
	int		c_nbr;
	int		c_found;
	int		e_nbr;
	int		p_pos[2];
	t_bool	exit_found;
}	t_map;

# define TX_SIZE 64

typedef struct s_data
{
	void	*mlx_ptr; // MLX pointer
	int		width;
	int		height;
	char	**map;
	int		c_nbr;
	int		c_found;
	int		pos_x;
	int		pos_y;
	int		mvt_count;
	t_bool	exit_ok;
	t_bool	error;
	//mlx_image_t *background[5];
	mlx_image_t *wall_img;
	mlx_image_t *grass_img;
	mlx_image_t *collect;
	mlx_image_t *cave;

	mlx_image_t *up[3];
	mlx_image_t *down[3];
	mlx_image_t *left[3];
	mlx_image_t *right[3];
	//void	*win_ptr; // MLX window pointer
	//void	*textures[5]; // MLX image pointers
}	t_data;

void	error_func(char *err_msg);
char	*map_append(char *map_str, char *buffer);
void	init_struct(t_map *smap);

//	map functions	//

void	check_map(t_map *smap);
void	get_map(t_map *lsl, char **argv);
void	map_size(t_map *smap);
void	map_borders(t_map *smap);
void	map_icons(t_map *smap);
int		char_check(char c, char *str);
char	**array_copy(char **array);
void	check_path(t_map *smap);
void	map_name(char **argv);
void	reader(int rd, int fd, char *buffer, char **map_str);
char	*map_append(char *map_str, char *buffer);
void	check_nline(t_map *smap, char *map_str);
void	flood_fill(int pos_y, int pos_x, char **map, t_map *smap);

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

#endif