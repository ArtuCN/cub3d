/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:56:10 by aconti            #+#    #+#             */
/*   Updated: 2024/08/01 12:10:56 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (1);
}

int main(int ac, char **av)
{
	t_cub cub;
	t_data data;
	
	cub.data = &data;
	data.cub = &cub;
	(void)av;
	if (ac == 2)
	{
		if (!regular_map(av[1], &cub))
			return (0);
		if (!init_cube(&cub))
			return (0);
	}
	else
		return(printf("Error\n"), 0);
	// free_matrix(cub.map);
	// free(cub.img);
}
