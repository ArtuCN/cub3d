/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:34:58 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 15:32:53 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_door(int x, int y, t_cub *cub)
{
	int	i;
	int	j;

	j = (y / TXT_SIZE);
	i = (x / TXT_SIZE);
	if (!cub->data->map[j])
		return (0);
	if (cub->data->map[j][i] == 'D')
		return (1);
	return (0);
}

void	some_other_init(t_dda *dda, t_player *player, long double temp_ang)
{
	dda->pos_x = player->x;
	dda->pos_y = player->y;
	dda->ray_dir_x = cos(temp_ang * PI / 180.0);
	dda->ray_dir_y = sin(temp_ang * PI / 180.0);
	dda->delta_dist_x = fabs(1.0 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->ray_dir_y);
	dda->hit = 0;
	dda->angle = temp_ang;
}

void	finishing_init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i)
{
	ray[i].wall = malloc(sizeof(t_wall));
	ray[i].wall->distance = ray[i].distance;
	ray[i].wall->door = 0;
	if (is_door(dda->pos_x, dda->pos_y, cub))
		ray[i].wall->door = 1;
	add_direction(&ray[i], dda);
	ray[i].x = dda->pos_x / TXT_SIZE;
	ray[i].y = dda->pos_y / TXT_SIZE;
	get_w_h(&ray[i], cub);
	ray[i].wall->id = cub->num_walls;
	cub->num_walls++;
}

void	init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i)
{
	double	corrected_distance;

	if (dda->side == 0)
		ray[i].distance = dda->side_dist_x - dda->delta_dist_x;
	else
		ray[i].distance = dda->side_dist_y - dda->delta_dist_y;
	ray[i].angle = dda->angle;
	ray[i].x = dda->pos_x;
	ray[i].y = dda->pos_y;
	corrected_distance = ray[i].distance
		* cos((ray[i].angle - cub->player->angle) * (PI / 180.0)) / TXT_SIZE;
	ray[i].distance = fabs(corrected_distance);
	ray[i].wall_height = HEIGHT / ray[i].distance;
	ray[i].wall_start = -ray[i].wall_height / 2 + (HEIGHT / 2);
	ray[i].wall_end = ray[i].wall_height / 2 + (HEIGHT / 2);
	if (is_same(cub, ray, i))
		ray[i].wall = ray[i - 1].wall;
	else
		finishing_init_ray(ray, dda, cub, i);
	ray[i].hit_x = ((dda->pos_x) + ray->distance * dda->ray_dir_x) / TXT_SIZE;
	ray[i].hit_y = ((dda->pos_y) + ray->distance * dda->ray_dir_y) / TXT_SIZE;
}

void	dist(t_dda *dda, t_cub *cub, t_ray *ray, int i)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->pos_x += dda->step_x;
		dda->side = 0;
		dda->hit = is_wall(dda->pos_x, dda->pos_y, cub);
		if (dda->hit == 0)
		{
			ray[i].from_x = dda->pos_x;
			ray[i].from_y = dda->pos_y;
		}
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->pos_y += dda->step_y;
		dda->side = 1;
		dda->hit = is_wall(dda->pos_x, dda->pos_y, cub);
		if (dda->hit == 0)
		{
			ray[i].from_x = dda->pos_x;
			ray[i].from_y = dda->pos_y;
		}
	}
}
