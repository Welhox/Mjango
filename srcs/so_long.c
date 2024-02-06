/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/06 13:42:44 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	get_map(t_struct *lstruct, char **argv)

{
	int	i;
	int	fd;
	char	*map_str;

	map_str = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	//This needs fixing
	lstruct->map = malloc(100);
		while (i >= 0 && i < 100)
	{
		lstruct->map[i] = get_next_line(fd);
		if (!lstruct->map[i])
			break;
		i++;
	}

/* 	while (rd > 0)
	{
		rd = read(fd, map_str, 100);
		map_str[rd] = '\0';
	} */
/* 	while (get_next_line(fd))
		i++; */
	//close(fd);
	
	//fd = open(argv[1], O_RDONLY);

	//lstruct->map[k] = NULL;
	close(fd);
	i = 0;
	while (lstruct->map[i])
	{
		ft_printf("%s", lstruct->map[i]);
		i++;
	}
	ft_printf("\n");
}

/* int		ft_search(const char *s, int c)

{
	while (*s != '\0')
	{
		if ((char)c == *s)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	else
		return (0);
} */

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
	check_map(&lstruct);
}





/* • open, close, read, write,
malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm compiler option,
man man 3 math)
• All functions of the MiniLibX */