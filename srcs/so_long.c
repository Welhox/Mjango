/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:45 by clundber          #+#    #+#             */
/*   Updated: 2024/02/05 17:11:14 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	get_map(t_struct *lstruct, char **argv)

{
	int	i;
	int	fd;
	int	k;

	k = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd))
		i++;
	close(fd);
	lstruct->map = malloc(sizeof(char*) * (i +1));
	fd = open(argv[1], O_RDONLY);
	while (i >= 0)
	{
		lstruct->map[k] = get_next_line(fd);
		k++;
		i--;
	}
	lstruct->map[k] = NULL;
	close(fd);
	i = 0;
	while (lstruct->map[i])
	{
		ft_printf("%s\n", lstruct->map[i]);
		i++;
	}
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
}





/* • open, close, read, write,
malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm compiler option,
man man 3 math)
• All functions of the MiniLibX */