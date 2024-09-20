/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:06:27 by aconti            #+#    #+#             */
/*   Updated: 2024/09/20 14:45:09 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	adding_ray_info(t_ray *ray)
{
	ray->wall_start = (HEIGHT / 2) - (HEIGHT / ray->distance);
	ray->wall_end = (HEIGHT / 2) + (HEIGHT / ray->distance);
}

int	diff_dir(t_ray *old, t_ray *ray)
{
	if (old->from_x == ray->x && old->from_y == ray->y)
		return (0);
	return (1);
}

int	is_same(t_ray *ray, int i)
{
	int	j;
	int	k;

	j = (ray[i].y * 50 / HEIGHT);
	k = (ray[i].x * 50 / WIDTH);
	if (i > 0)
	{
		if (k == ray[i - 1].wall->x && j == ray[i - 1].wall->y && !diff_dir(&ray[i - 1], &ray[i]))
			return (1);
	}
	return (0);
}
