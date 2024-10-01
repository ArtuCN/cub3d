/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:34:12 by aconti            #+#    #+#             */
/*   Updated: 2024/10/01 16:10:30 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_door(int x, int y, t_cub *cub)
{
	int i;
	int j;
	j = (y / TXT_SIZE);
	i = (x / TXT_SIZE);
	if (!cub->data->map[j])
		return (0);
	if (cub->data->map[j][i] == 'D')
		return (1);
	return (0);
}

void	add_direction(t_ray *ray, t_dda *dda)
{
	
	if ((dda->sideDistX == dda->sideDistY))
	{
		ray->wall->direction = 'A'; // Colpito un angolo
	}
	else if (dda->side == 0)
	{	
		if (dda->rayDirX > 0)
			ray->wall->direction = 'E';
		else if (dda->rayDirX < 0)
			ray->wall->direction = 'W';
	} 
	else if (dda->side == 1)
	{
		if (dda->rayDirY > 0)
			ray->wall->direction = 'S';
		else if (dda->rayDirY < 0)
			ray->wall->direction = 'N';
	}
	printf("DIR = %c\n", ray->wall->direction);
}

void	add_position(t_wall *wall, int x, int y)
{
	wall->x = x / TXT_SIZE;
	wall->y = y / TXT_SIZE;
}

void	init_dda(t_dda *dda, t_player *player, long double temp_ang)
{
	dda->posX = player->x;
	dda->posY = player->y;
	dda->rayDirX = cos(temp_ang * PI / 180.0);
	dda->rayDirY = sin(temp_ang * PI / 180.0);
	dda->deltaDistX = fabs(1.0 / dda->rayDirX);
	dda->deltaDistY = fabs(1.0 / dda->rayDirY);
	dda->hit = 0;
	dda->angle = temp_ang;
	if (dda->rayDirX > 0)
	{
		dda->stepX = 1;
		dda->sideDistX = (player->x - dda->posX) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = -1;
		dda->sideDistX = (dda->posX + 1.0 - player->x) * dda->deltaDistX;
	}
	if (dda->rayDirY > 0)
	{
		dda->stepY = 1;
	    dda->sideDistY = (player->y - dda->posY) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = -1;
		dda->sideDistY = (dda->posY + 1.0 - player->y) * dda->deltaDistY;
	}
}


double map2(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



void	init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i)
{
	double corrected_distance;
	
	if (dda->side == 0)
		ray[i].distance = dda->sideDistX - dda->deltaDistX;
	else
		ray[i].distance = dda->sideDistY - dda->deltaDistY;
	ray[i].angle = dda->angle;
	ray[i].x = dda->posX;
	ray[i].y = dda->posY;
	corrected_distance = ray[i].distance * cos((ray[i].angle - cub->player->angle) * (PI / 180.0)) / TXT_SIZE;
	ray[i].distance = fabs(corrected_distance);
	ray[i].wall_height = HEIGHT / ray[i].distance;
	ray[i].wall_start = -ray[i].wall_height / 2 + (HEIGHT / 2);
	ray[i].wall_end = ray[i].wall_height / 2 + (HEIGHT / 2);
	if (is_same(cub, ray, i))
		ray[i].wall = ray[i - 1].wall;
	else
	{
		ray[i].wall = malloc(sizeof(t_wall));
		ray[i].wall->distance = ray[i].distance;
		ray[i].wall->door = 0;
		if (is_door(dda->posX, dda->posY, cub))
			ray[i].wall->door = 1;
		add_direction(&ray[i], dda);
		add_position(ray[i].wall, dda->posX, dda->posY);
		get_w_h(&ray[i], cub);
		ray[i].wall->id = cub->num_walls;
		cub->num_walls++;
		printf("NUMERO DI PARETI = %d\n", cub->num_walls);
	}
	ray[i].hit_x = ((dda->posX) + ray->distance * dda->rayDirX) / TXT_SIZE;
	ray[i].hit_y = ((dda->posY) + ray->distance * dda->rayDirY) / TXT_SIZE;
	// ray[i].hit_y = map2(ray[i].hit_y, ray[i].y, ray[i].y + 0.5, ray[i].y - 0.5, ray[i].y + 0.5);
	// ray[i].hit_x = map2(ray[i].hit_x, ray[i].x, ray[i].x + 0.5, ray[i].x - 0.5, ray[i].x + 0.5);
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
				if (dda->hit == 0)
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
		if (temp_ang > 360)
			temp_ang = temp_ang - 360;
	}
	free(dda);
	wall_draw_info(cub, ray);
	// adding_pix_to_img(cub, ray);
}
