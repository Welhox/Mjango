/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/08 16:49:04 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	get_map(t_struct *lstruct, char **argv)

{
	int		i;
	int		fd;
	char	*map_str;
	//char	ptr;
	char	*temp;

	temp = NULL;
	//ptr = NULL;
	map_str = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	map_str = get_next_line(fd);
	if (!map_str)
		exit(1); // add invalid map etc
	while (1)
	{
		//ptr = &map_str;
		temp = ft_strjoin(map_str, get_next_line(fd));
		if (temp != NULL) 
		{
			free(map_str);
			map_str = NULL;
			map_str = ft_strdup(temp);
			free (temp);
			temp = NULL;
		}
		else
			break;

		//free (&ptr);
	}
	close (fd);
	ft_printf("%s", map_str);
	free (map_str);
/* 	//This needs fixing
	lstruct->map = malloc(100);
		while (i >= 0 && i < 100)
	{
		lstruct->map[i] = get_next_line(fd);
		if (!lstruct->map[i])
			break;
		i++;
	}

	close(fd); */
	i = 0;
	while (lstruct->map[i])
	{
		ft_printf("%s", lstruct->map[i]);
		i++;
	}
	ft_printf("\n");
}

void	check_map(t_struct *lstruct)

{
	int	x;
	int	y;
	//int	temp;
	char	valid[7] = "01CEP\n";
	int	i;

	x = 0;
	y = 0;
	while (lstruct->map[0][x])
		x++;
	lstruct->map_width = x;
	while (lstruct->map[y])
		y++;
	//ft_printf("ok2\n");
	lstruct->map_depth = y;
	y = 0;
	while (lstruct->map[y])
	{
		i = 0;
		while (valid[i])
		{
			if (ft_strchr(lstruct->map[y], valid[i])  != 0)
				i++;		
			else
				error_func(lstruct, "Non valid map\n");
		}
/* 		while (valid[i])
		{
			if (ft_search(lstruct->map[y], valid[i])  == 1)
				error_func(lstruct, "Non valid map\n");
			else
				i++;
		} */
		y++;
	}
}

void	error_func(t_struct *lstruct, char *err_msg)

{
	// to silence error
	lstruct->map_depth = 0;
	//free_function for struct
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

int	main(int argc, char *argv[])

{
	t_struct lstruct;		
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}	
	get_map(&lstruct, argv);
	//check_map(&lstruct);
}





/* • open, close, read, write,
malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm compiler option,
man man 3 math)
• All functions of the MiniLibX */