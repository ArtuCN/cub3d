/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:34:12 by aconti            #+#    #+#             */
/*   Updated: 2024/09/25 17:16:15 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_door(int x, int y, t_cub *cub)
{
	int i;
	int j;
	j = (y * 50 / HEIGHT);
	i = (x * 50 / HEIGHT);
	if (!cub->data->map[i])
		return (0);
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
    	else if(dda->rayDirX < 0)
			ray->wall->direction = 'W';
	} 
	else if (dda->side == 1)
	{
    	if (dda->rayDirY > 0)
        	ray->wall->direction = 'S';
    	else if (dda->rayDirY < 0)
        	ray->wall->direction = 'N';
	}
	else
		ray->wall->direction = 'A';
}

void	add_position(t_wall *wall, int x, int y)
{
	wall->x = x * 50 / HEIGHT;
	wall->y = y * 50 / HEIGHT;
}

void	init_dda(t_dda *dda, t_player *player, long double temp_ang)
{
	dda->posX = (int)player->x;
	dda->posY = (int)player->y;
	dda->rayDirX = cos(temp_ang * PI / 180.0);
	dda->rayDirY = sin(temp_ang * PI / 180.0);
	// if (dda->rayDirX == 0)
	// 	dda->deltaDistX = 1e30;
	// else
		dda->deltaDistX = fabs(1.0 / dda->rayDirX);
	// if (dda->rayDirY == 0)
	// 	dda->deltaDistY = 1e30;
	// else
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

void	init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i)
{
	double corrected_distance;
	// if (dda->sideDistX < dda->sideDistY)
	// 	ray[i].distance = (dda->posX - cub->player->x + (1 - dda->stepX) / 2.0) / dda->rayDirX;
	// else
	// 	ray[i].distance = (dda->posY - cub->player->y + (1 - dda->stepY) / 2.0) / dda->rayDirY;

	if (dda->side == 0)
		ray[i].distance = dda->sideDistX - dda->deltaDistX;
	else
		ray[i].distance = dda->sideDistY - dda->deltaDistY;
		
	ray[i].angle = dda->angle;
	corrected_distance = ray[i].distance * cos((ray[i].angle - cub->player->angle) * (PI / 180.0));
	ray[i].distance = fabs(corrected_distance);
	ray[i].x = dda->posX;
	ray[i].y = dda->posY;
	// ray[i].wall_start = (HEIGHT / 2.0) - (HEIGHT / ray[i].distance);
	// ray[i].wall_end = (HEIGHT / 2.0) + (HEIGHT / ray[i].distance);
	// ray[i].wall_height = ray[i].wall_end - ray[i].wall_start;

	ray[i].wall_height = HEIGHT / ray[i].distance;
	ray[i].wall_start = -ray[i].wall_height / 2 + (HEIGHT / 2);
	ray[i].wall_end = ray[i].wall_height / 2 + (HEIGHT / 2);
	// min();
	if (is_same(ray, i))
		ray[i].wall = ray[i - 1].wall;
	else
	{
		ray[i].wall = malloc(sizeof(t_wall));
		ray[i].wall->distance = ray[i].distance;
		add_direction(&ray[i], dda);
		add_position(ray[i].wall, dda->posX, dda->posY);
		ray[i].wall->door = 0;
		if (is_door(dda->posX, dda->posY, cub))
			ray[i].wall->door = 1;
		get_w_h(&ray[i], cub);
		cub->num_walls++;
	}
	ray[i].hit_x = cub->player->x + ray->distance * dda->rayDirX;
	if (ray[i].hit_x < 0)
		ray[i].hit_x = 0;
	ray[i].hit_y = cub->player->x + ray->distance * dda->rayDirY;
	if (ray[i].hit_y > HEIGHT - 1)
		ray[i].hit_y = HEIGHT - 1;
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
		// printf("Ray %d - Distance: %Lf, Player X: %f, Player Y: %f, PosX: %d, PosY: %d\n",
    //    i, ray[i].distance, cub->player->x, cub->player->y, dda->posX, dda->posY);
		// printf("start wall %f end wall %f %d\n", ray[i].wall_start, ray[i].wall_end, i);
		// printf("wall height %f ID %d\n", ray[i].wall_height, i);
		// printf("distance %Lf id %d\n", ray[i].distance, i);
		temp_ang += cub->player->increment;
		if (temp_ang > 360)
			temp_ang = temp_ang - 360;
	}
	free(dda);
	adding_pix_to_img(cub, ray);
}
