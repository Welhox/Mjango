/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:50:11 by clundber          #+#    #+#             */
/*   Updated: 2024/02/09 19:33:51 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_borders(t_map *smap)

{
	int	x;
	int	y;

	y = 0;
	while (smap->map[y])
	{
		x = 0;
		while (smap->map[y][x])
			x++;
		if (smap->map[y][0] != '1' || smap->map[y][x -1] != '1')
			smap->error = true;
		y++;
	}
	x = 0;
	while (smap->map[0][x])
	{
		if (smap->map[0][x] != '1')
			smap->error = true;
		x++;
	}
	x = 0;
	while (smap->map[0][x])
	{
		if (smap->map[y -1][x] != '1')
			smap->error = true;
		x++;
	}
}

void	map_size(t_map *smap)
{
	int	y;
	int	x;
	int	width;

	width = 0;
	x = 0;
	y = 0;
	while (smap->map[0][width])
		width++;
	while (smap->map[y])
	{
		while (smap->map[y][x])
			x++;
		if (x != width)
			smap->error = true;
		x = 0;
		y++;
	}
	if (y  < 3 || width < 3)
		smap->error = true;
	smap->map_height = y;
	smap->map_width = width;
}

char	*map_append(char *map_str, char *buffer)

{
	char	*temp;

	temp = NULL;
	temp = ft_strjoin(map_str, buffer);
	free (map_str);
	return (temp);
}

void	check_nline(t_map *smap, char *map_str)

{
	int	i;

	i = 0;
	if (map_str[0] == '\n')
		smap->error = true;
	while (map_str[i])
		i++;
	if (map_str[i -1] == '\n')
		smap->error = true;
	if (ft_strnstr(map_str, "\n\n", ft_strlen(map_str)) != 0)
		smap->error = true;
}

void	get_map(t_map  *smap, char **argv)

{
	int		i;
	int		fd;
	char	*map_str;
	char	buffer[501];
	int		rd;

	map_str = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}

	rd = read(fd, buffer, 500);
	buffer[rd] = '\0';
	map_str = ft_strdup(buffer);
	while (rd != 0) // this needs fixing later, also adding malloc checks & rd fail checks.
	{
		rd = read(fd, buffer, 500);
		buffer[rd] = '\0';
		map_str = map_append(map_str, buffer);
	}
	close (fd);
	check_nline(smap, map_str);
	if (smap->error == true)
		error_func(smap, "map faulty\n"); // add freeing
 	smap->map = ft_split(map_str, '\n');
	free(map_str);
}

int	char_check(char c)

{
	char	str[6] = "01CEP";
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return(1);
		i++;
	}
	return(0);
}

void	map_icons(t_map *smap)

{
	int	x;
	int	y;

	y = 0;
	while (smap->map[y])
	{
		x = 0;
		while (smap->map[y][x])
		{
			if (char_check(smap->map[y][x]) == 0)
				smap->error = true;
			if(smap->map[y][x] == 'P')
			{
				smap->p_nbr++;
				smap->p_pos[0] = y;
				smap->p_pos[1] = x;
			}
			if (smap->map[y][x] == 'C')
				smap->c_nbr++;
			if (smap->map[y][x] == 'E')
				smap->e_nbr++;
			x++;
		}
		y++;
	}
}

void	check_map(t_map  *smap)

{
	map_size(smap);
	map_borders(smap);
	map_icons(smap);
	check_path(smap);
	
	if (smap->p_nbr != 1 || smap->c_nbr < 1 || smap->e_nbr != 1)
		smap->error = true;
	if (smap->error == true)
		error_func(smap, "map faulty\n");
}