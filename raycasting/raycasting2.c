/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:02 by aconti            #+#    #+#             */
/*   Updated: 2024/09/23 16:06:03 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void	get_w_h(t_ray *ray, t_cub *cub)
{
	if (ray->wall->door == 1)
	{
		ray->wall->width = cub->wall_cub[DOOR].width;
		ray->wall->height = cub->wall_cub[DOOR].height;
	}
	else if (ray->wall->direction == 'N')
	{
		ray->wall->width = cub->wall_cub[WALL_N].width;
		ray->wall->height = cub->wall_cub[WALL_N].height;
	}
	else if (ray->wall->direction == 'S')
	{
		ray->wall->width = cub->wall_cub[WALL_S].width;
		ray->wall->height = cub->wall_cub[WALL_S].height;
	}
	else if (ray->wall->direction == 'E')
	{
		ray->wall->width = cub->wall_cub[WALL_E].width;
		ray->wall->height = cub->wall_cub[WALL_E].height;
	}
	else if (ray->wall->direction == 'W')
	{
		ray->wall->width = cub->wall_cub[WALL_W].width;
		ray->wall->height = cub->wall_cub[WALL_W].height;
	}
}

void	other_info(t_ray *ray, t_cub *cub)
{
	ray->hit_x = ray->x + ray->distance * cos(ray->angle * PI / 180);
	ray->hit_y = ray->y + ray->distance * sin(ray->angle * PI / 180);
	if (ray->wall->direction != 'A')
		get_w_h(ray, cub);
}

void	add_wall_info(t_ray *ray, char **map, t_cub *cub)
{
	int	i;
	int	j;
	int	k;
	int	h;

	j = (ray->y * 50 / HEIGHT);
	i = (ray->x * 50 / WIDTH);
	ray->wall->y = j;
	ray->wall->x = i;
	k = (ray->from_y * 50 / HEIGHT);
	h = (ray->from_x * 50 / WIDTH);
	if (map[j][i] == 'D')
		ray->wall->door = 1;
	else
		ray->wall->door = 0;
	if (h > i && k == j)
		ray->wall->direction = 'W';
	else if (h < i && k == j)
		ray->wall->direction = 'E';
	else if (h == i && k > j)
		ray->wall->direction = 'N';
	else if (h == i && k < j)
		ray->wall->direction = 'S';
	else
		ray->wall->direction = 'A';
	ray->wall->distance = ray->distance;
	ray->wall->first_hit_x = ray->hit_x - floor(ray->hit_x);
	ray->wall->first_hit_y = ray->hit_y - floor(ray->hit_y);
	other_info(ray, cub);
}
