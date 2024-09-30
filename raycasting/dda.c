/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:34:12 by aconti            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/30 10:40:19 by adonato          ###   ########.fr       */
=======
/*   Updated: 2024/09/27 17:01:42 by aconti           ###   ########.fr       */
>>>>>>> f687a146a221bd50a66b0f59e3622d3496248fec
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_door(int x, int y, t_cub *cub)
{
	int i;
	int j;

	j = (y * 50 / HEIGHT);
	i = (x * 50 / HEIGHT);
	if (!cub->data->map[j][i])
	j = (y / 10);
	i = (x / 10);
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
}

void	add_position(t_wall *wall, int x, int y)
{
	wall->x = x / 10;
	wall->y = y / 10;
}

void	init_dda(t_dda *dda, t_player *player, long double temp_ang)
{
	dda->posX = (int)player->x;
	dda->posY = (int)player->y;
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

void	init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i)
{
	double corrected_distance;
	
	if (dda->side == 0)
		ray[i].distance = dda->sideDistX - dda->deltaDistX;
	else
		ray[i].distance = dda->sideDistY - dda->deltaDistY;
		
	ray[i].angle = dda->angle;
	corrected_distance = ray[i].distance * cos((ray[i].angle - cub->player->angle) * (PI / 180.0));
	ray[i].distance = fabs(corrected_distance) / 10;
	ray[i].x = dda->posX;
	ray[i].y = dda->posY;
	ray[i].wall_height = HEIGHT / ray[i].distance;
	ray[i].wall_start = -ray[i].wall_height / 2 + (HEIGHT / 2);
	ray[i].wall_end = ray[i].wall_height / 2 + (HEIGHT / 2);
	if (is_same(cub, ray, i))
		ray[i].wall = ray[i - 1].wall;
	else
	{
		ray[i].wall = malloc(sizeof(t_wall));
		if (!ray[i].wall)
        {
            printf("Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
		ray[i].wall->distance = ray[i].distance;
		ray[i].wall->door = 0;
		if (is_door(dda->posX, dda->posY, cub))
			ray[i].wall->door = 1;
		add_direction(&ray[i], dda);
		add_position(ray[i].wall, dda->posX, dda->posY);
		get_w_h(&ray[i], cub);
		ray[i].wall->id = cub->num_walls;
		cub->num_walls++;
	}
<<<<<<< HEAD
    ray[i].hit_x = cub->player->x + ray[i].distance * dda->rayDirX * 50 / WIDTH;
    if (ray[i].hit_x < 0)
        ray[i].hit_x = 0;
    if (ray[i].hit_x > HEIGHT - 1)
        ray[i].hit_x = HEIGHT - 1;

    ray[i].hit_y = cub->player->y + ray[i].distance * dda->rayDirY * 50 / HEIGHT;
    if (ray[i].hit_y < 0)
        ray[i].hit_y = 0;
    if (ray[i].hit_y > HEIGHT - 1)
        ray[i].hit_y = HEIGHT - 1;
=======
	ray[i].hit_x = cub->player->x + ray->distance * dda->rayDirX / 10;
	if (ray[i].hit_x < 0)
		ray[i].hit_x = 0;
	ray[i].hit_y = cub->player->y + ray->distance * dda->rayDirY / 10;
	if (ray[i].hit_y > HEIGHT - 1)
		ray[i].hit_y = HEIGHT - 1;
>>>>>>> f687a146a221bd50a66b0f59e3622d3496248fec
}

int	is_wall2(long double x, long double y, t_cub *cub)
{
	long double	j;
	long double	i;

	if (x < 0 || y < 0 || x > HEIGHT || y > HEIGHT)
		return (1);
	j = (y / 10);
	i = (x / 10);
	if (cub->data->map[(int)j][(int)i] == '1'
		|| cub->data->map[(int)j][(int)i] == '\n'
		|| !cub->data->map[(int)j][(int)i]
		|| cub->data->map[(int)j][(int)i] == 'D')
		return (1);
	return (0);
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
				dda->hit = is_wall2(dda->posX, dda->posY, cub);
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
				// printf("posX %d posY %d\n", dda->posX, dda->posY);
				dda->hit = is_wall2(dda->posX, dda->posY, cub);
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
	adding_pix_to_img(cub, ray);
}
