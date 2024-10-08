/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:34:12 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 15:32:00 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_direction(t_ray *ray, t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->ray_dir_x > 0)
			ray->wall->direction = 'E';
		else if (dda->ray_dir_x < 0)
			ray->wall->direction = 'W';
	}
	else if (dda->side == 1)
	{
		if (dda->ray_dir_y > 0)
			ray->wall->direction = 'S';
		else if (dda->ray_dir_y < 0)
			ray->wall->direction = 'N';
	}
}

void	add_position(t_wall *wall, int x, int y)
{
	wall->x = x / TXT_SIZE;
	wall->y = y / TXT_SIZE;
}

void	init_dda(t_dda *dda, t_player *player, long double temp_ang)
{
	some_other_init(dda, player, temp_ang);
	if (dda->ray_dir_x > 0)
	{
		dda->step_x = 1;
		dda->side_dist_x = (player->x - dda->pos_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = -1;
		dda->side_dist_x = (dda->pos_x + 1.0 - player->x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y > 0)
	{
		dda->step_y = 1;
		dda->side_dist_y = (player->y - dda->pos_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = -1;
		dda->side_dist_y = (dda->pos_y + 1.0 - player->y) * dda->delta_dist_y;
	}
}

void	start_dda(t_cub *cub, t_ray *ray)
{
	int			i;
	t_dda		*dda;
	long double	temp_ang;

	i = -1;
	dda = malloc(sizeof(t_dda));
	cub->dda = dda;
	temp_ang = (long double)(cub->player->angle - 30);
	cub->num_walls = 0;
	while (++i < WIDTH)
	{
		init_dda(dda, cub->player, temp_ang);
		ray[i].from_x = dda->pos_x;
		ray[i].from_y = dda->pos_y;
		while (dda->hit == 0)
			dist(dda, cub, ray, i);
		init_ray(ray, dda, cub, i);
		temp_ang += cub->player->increment;
		if (temp_ang > 360)
			temp_ang = temp_ang - 360;
	}
	free(dda);
	adding_pix_to_img(cub, ray);
}
