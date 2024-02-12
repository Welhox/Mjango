/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/12 14:02:57 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_func(char *err_msg)

{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

void	init_struct(t_map *smap)

{
	smap->map = NULL;
	smap->map_height = 0;
	smap->map_width = 0;
	smap->error = false;
	smap->p_nbr = 0;
	smap->c_nbr = 0;
	smap->c_found = 0;
	smap->e_nbr = 0;
	smap->p_pos[0] = 0;
	smap->p_pos[1] = 0;
	smap->exit_found = false;
}

void	map_name(char **argv)

{
	int	i;

	i = 0;
	while (argv[1] && argv[1][i])
		i++;
	if (i < 5)
		error_func("incorrect map name\n");
	if (i > 4)
	{
		if (argv[1][i -1] != 'r' || argv[1][i -2] != 'e' ||
		argv[1][i -3] != 'b' || argv[1][i -4] != '.')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
}

int	main(int argc, char *argv[])

{
	t_map	smap;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	init_struct(&smap);
	map_name(argv);
	get_map(&smap, argv);
	if (!smap.map)
		error_func("malloc fail\n");
	check_map(&smap);
/* 	int	i;
	i = 0;
	while (smap.map[i])
	{
	ft_printf("%s\n", smap.map[i]);
	i++;
	} */
	ft_arrfree(smap.map);
	ft_printf("Great sucess\n");
}

/* • open, close, read, write,
malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm compiler option,
man man 3 math)
• All functions of the MiniLibX */