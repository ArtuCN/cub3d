/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:02 by aconti            #+#    #+#             */
/*   Updated: 2024/09/20 17:06:55 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_rays(t_player *player)
{
	int	i;

	i = -1;
	while (++i < player->num_rays)
	{
		// printf("Ray %d: x = %f, y = %f, angle = %f, distance = %Lf\n",
		// 	i, player->ray[i].x, player->ray[i].y,
		// 	player->ray[i].angle, player->ray[i].distance);
		// printf("Wall: x = %d, y = %d\n", player->ray[i].wall->x,
		// 	player->ray[i].wall->y);
		// printf("Wall direction: %c\n", player->ray[i].wall->direction);
		// printf("wall start and end: %f, %f\n",
		// 	player->ray[i].wall->wall_start, player->ray[i].wall->wall_end);
		printf("ray hit x and y: %Lf, %Lf\n",
			player->ray[i].hit_x, player->ray[i].hit_y);
		printf("wall hit x and y: %Lf, %Lf\n",
			player->ray[i].wall->wall_hit_x, player->ray[i].wall->wall_hit_y);
	}
}

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
	ray->wall->wall_hit_x = ray->hit_x - (long double)floor(ray->hit_x);
	ray->wall->wall_hit_y = ray->hit_y - (long double)floor(ray->hit_y);
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
	ray->wall->wall_start = (HEIGHT / 2) - (HEIGHT / ray->distance);
	ray->wall->wall_end = (HEIGHT / 2) + (HEIGHT / ray->distance);
	other_info(ray, cub);
}
