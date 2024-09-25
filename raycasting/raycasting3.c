/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:06:27 by aconti            #+#    #+#             */
/*   Updated: 2024/09/25 17:13:23 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	adding_ray_info(t_ray *ray)
{
	ray->hit_x = ray->x + ray->distance * cos(ray->angle * PI / 180);
	ray->hit_y = ray->y + ray->distance * sin(ray->angle * PI / 180);
	ray->wall_start = (HEIGHT / 2) - (HEIGHT / ray->distance);
	ray->wall_end = (HEIGHT / 2) + (HEIGHT / ray->distance);
}

int	same_dir(t_ray *old, t_ray *ray)
{
	int j;
	int k;
	int h;
	int i;

	h = (old->from_x * 50 / HEIGHT);
	i = (old->from_y * 50 / HEIGHT);
	j = (ray->from_y * 50 / HEIGHT);
	k = (ray->from_x * 50 / HEIGHT);	
	if (h  == k && i == j)
		return (1);
	return (0);
}

int	is_same(t_ray *ray, int i)
{
	int	j;
	int	k;

	j = (ray[i].y * 50 / HEIGHT);
	k = (ray[i].x * 50 / HEIGHT);
	if (i > 0)
	{
		if ((k == (int)ray[i - 1].wall->x && j == (int)ray[i - 1].wall->y) && same_dir(&ray[i - 1], &ray[i]))
			return (1);//uguali
	}
	return (0);//diversi
}
