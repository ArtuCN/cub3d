/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:34:12 by aconti            #+#    #+#             */
/*   Updated: 2024/09/24 14:06:52 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_door(int x, int y, t_cub *cub)
{
	int i;
	int j;
	j = (y * 50 / HEIGHT);
	i = (x * 50 / WIDTH);
	if (cub->data->map[i][j] == 'D')
		return (1);
	return (0);
}

void	add_direction(t_ray *ray, t_dda *dda)
{
	if (dda->side == 0)
    {	
		if (dda->rayDirX > 0)
			ray->wall->direction = 'E';
    	else
			ray->wall->direction = 'W';
	} 
	else 
	{
    	if (dda->rayDirY > 0)
        	ray->wall->direction = 'S';
    	else
        	ray->wall->direction = 'N';
	}
}

void	init_dda(t_dda *dda, t_player *player, long double temp_ang)
{
	dda->posX = (int)player->x;
	dda->posY = (int)player->y;
	dda->rayDirX = cos(temp_ang * PI / 180);
	dda->rayDirY = sin(temp_ang * PI / 180);
	dda->deltaDistX = fabs(1 / dda->rayDirX);
	dda->deltaDistY = fabs(1 / dda->rayDirY);
	dda->hit = 0;
	dda->angle = temp_ang;
	if (dda->rayDirX > 0)
	{
		dda->stepX = 1;
		dda->sideDistX = (dda->posX + 1.0 - player->x) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = -1;
		dda->sideDistX = (player->x - dda->posX) * dda->deltaDistX;
	}
	if (dda->rayDirY > 0)
	{
		dda->stepY = 1;
		dda->sideDistY = (dda->posY + 1.0 - player->y) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = -1;
	    dda->sideDistY = (player->y - dda->posY) * dda->deltaDistY;
	}	
}

void	init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i)
{
	if (dda->sideDistX < dda->sideDistY)
		ray[i].distance = (dda->posX - cub->player->x + (1 - dda->stepX) / 2) / dda->rayDirX;
	else
		ray[i].distance = (dda->posY - cub->player->y + (1 - dda->stepY) / 2) / dda->rayDirY;
	ray[i].x = dda->posX;
	ray[i].y = dda->posY;
	ray[i].angle = dda->angle;
	ray[i].wall_start = (HEIGHT / 2) - (HEIGHT / ray[i].distance);
	ray[i].wall_end = (HEIGHT / 1.5) + (HEIGHT / ray[i].distance);
	if (is_same(ray, i))
		ray[i].wall = ray[i - 1].wall;
	else
	{
		ray[i].wall = malloc(sizeof(t_wall));
		ray[i].wall->distance = ray[i].distance;
		add_direction(&ray[i], dda);
		ray[i].wall->door = 0;
		//printf("x: %d, y: %d, map: %c\n", dda->posX, dda->posY, cub->data->map[(dda->posY * 50 / WIDTH)][(dda->posY * 50 / HEIGHT)]);
		if (is_door(dda->posX, dda->posY, cub))
			ray[i].wall->door = 1;
		get_w_h(&ray[i], cub);
		cub->num_walls++;
	}
	ray[i].hit_x = dda->posX;
	ray[i].hit_y = dda->posY;
	//printf("Ray: %d, wall_start: %f, wall_end: %f, distance: %Lf\n", i, ray[i].wall_start, ray[i].wall_end, ray[i].distance);
	//printf("posX: %d, posY: %d, angle: %Lf\n", dda->posX, dda->posY, dda->angle);
}

void	start_dda(t_cub *cub, t_ray *ray)
{
	int	i;
	t_dda	*dda;
	i = -1;
	long double temp_ang;
	
	dda = malloc(sizeof(t_dda));
	cub->dda = dda;
	temp_ang = (long double)(cub->player->angle - 30);
	cub->num_walls = 0;
	while (++i < WIDTH)
	{
		init_dda(dda, cub->player, temp_ang);
		ray[i].from_x = dda->posX;
		ray[i].from_y = dda->posY;
		while (dda->hit == 0)
		{
			if (dda->sideDistX < dda->sideDistY)
			{
				dda->sideDistX += dda->deltaDistX;
				dda->posX += dda->stepX;
				dda->side = 0;
				dda->hit = is_wall(dda->posX, dda->posY, cub);
				{
					ray[i].from_x = dda->posX;
					ray[i].from_y = dda->posY;
				}
			}
			else
			{
				dda->sideDistY += dda->deltaDistY;
				dda->posY += dda->stepY;
				dda->side = 1;
				dda->hit = is_wall(dda->posX, dda->posY, cub);
				if (dda->hit == 0)
				{
					ray[i].from_x = dda->posX;
					ray[i].from_y = dda->posY;
				}
			}
		}
		init_ray(ray, dda, cub, i);
		temp_ang += cub->player->increment;
	}
	free(dda);
	adding_pix_to_img(cub, ray);
}
