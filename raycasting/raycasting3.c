/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:06:27 by aconti            #+#    #+#             */
/*   Updated: 2024/10/01 15:28:05 by aconti           ###   ########.fr       */
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

	h = (old->from_x) / TXT_SIZE;
	i = (old->from_y) / TXT_SIZE;
	j = (ray->from_y) / TXT_SIZE;
	k = (ray->from_x) / TXT_SIZE;	
	if (h  == k && i == j)
		return (1);
	return (0);
}

int	is_same(t_cub *cub, t_ray *ray, int i)
{
	int	j;
	int	k;
	int h;
	int l;
	
	h = (ray[i - 1].y) / TXT_SIZE;
	l = (ray[i - 1].x) / TXT_SIZE;
	j = (ray[i].y) / TXT_SIZE;
	k = (ray[i].x) / TXT_SIZE;
	if (i > 0)
	{
		if (k == l && j == h && same_dir(&ray[i - 1], &ray[i])
			&& (cub->data->map[j][k] == cub->data->map[h][l]))
			return (1);//uguali
	}
	return (0);//diversi
}
