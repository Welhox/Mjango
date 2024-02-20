/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:12:29 by clundber          #+#    #+#             */
/*   Updated: 2024/02/20 19:21:34 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*map_append(char *map_str, char *buffer)

{
	char	*temp;

	temp = NULL;
	temp = ft_strjoin(map_str, buffer);
	free (map_str);
	return (temp);
}

void	check_nline(t_data *data, char *map_str)

{
	int	i;

	i = 0;
	if (map_str[0] == '\n')
		data->error = true;
	while (map_str[i])
		i++;
	if (map_str[i -1] == '\n')
		data->error = true;
	if (ft_strnstr(map_str, "\n\n", ft_strlen(map_str)) != 0)
		data->error = true;
}

void	reader(int rd, int fd, char *buffer, char **map_str)

{
	rd = read(fd, buffer, 500);
	if (rd <= 0)
		error_func("read failed or empty file\n");
	buffer[rd] = '\0';
	*map_str = ft_strdup(buffer);
	if (!map_str)
		error_func("Malloc failed\n");
	while (rd != 0)
	{
		rd = read(fd, buffer, 500);
		if (rd < 0)
		{
			free(*map_str);
			error_func("read failed");
		}
		buffer[rd] = '\0';
		*map_str = map_append(*map_str, buffer);
		if (!*map_str)
			error_func("Malloc failed\n");
	}
}

void	get_map(t_data *data, char **argv)

{
	int		fd;
	char	*map_str;
	char	buffer[501];
	int		rd;

	rd = 0;
	map_str = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	reader(rd, fd, buffer, &map_str);
	close (fd);
	check_nline(data, map_str);
	if (data->error == true)
	{
		free(map_str);
		error_func("Excess newlines in map\n");
	}
	data->map = ft_split(map_str, '\n');
	free(map_str);
}
