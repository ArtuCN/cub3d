/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:56:10 by aconti            #+#    #+#             */
/*   Updated: 2024/09/19 16:03:50 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)av;
	if (ac == 2)
	{
		cub.num_walls = 0;
		cub.pressed = 0;
		if (!regular_map(av[1], &cub))
			return (0);
		if (!init_cube(&cub))
			return (0);
	}
	else
		return (printf("Error\n"), 0);
}
