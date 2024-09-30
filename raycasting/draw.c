/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:23:00 by artucn            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/30 10:10:33 by adonato          ###   ########.fr       */
=======
/*   Updated: 2024/09/27 16:48:50 by aconti           ###   ########.fr       */
>>>>>>> f687a146a221bd50a66b0f59e3622d3496248fec
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int map(long double value, long double in_min, long double in_max, long double out_min, long double out_max)
{
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int	get_dir(char dir, int door)
{
	if (door == 1)
		return (DOOR);
	if (dir == 'N')
		return (WALL_N);
	else if (dir == 'S')
		return (WALL_S);
	else if (dir == 'W')
		return (WALL_W);
	else if (dir == 'E')
		return (WALL_E);
	return (0);
}

unsigned int	get_color(t_ray *ray, int i, t_cub *cub)
{
	int	offset;
	unsigned int color;
	int x;
	int	y;
	int dir;
	int start_cell;


	dir = get_dir(ray->wall->direction, ray->wall->door);
	if (dir == 'N' || dir == 'S')
	{
<<<<<<< HEAD
		start_cell = (int)(ray->hit_x / (HEIGHT / 50)) * (HEIGHT / 50);
		x = (ray->hit_x - start_cell) * ray->wall->width / (HEIGHT / 50);
	}
	else
	{
		start_cell = (int)(ray->hit_y / (HEIGHT / 50)) * (HEIGHT / 50);
		x = (ray->hit_y - start_cell) * ray->wall->width / (HEIGHT / 50);
=======
		start_cell = (int)(ray->hit_x / 10) * 10;
		x = (ray->hit_x - start_cell) * ray->wall->width / 10;
	}
	else
	{
		start_cell = (int)(ray->hit_y / 10) * 10;
		x = (ray->hit_y - start_cell) * ray->wall->width / 10;
>>>>>>> f687a146a221bd50a66b0f59e3622d3496248fec
	}
    // x = (int)((ray->hit_x - floor(ray->hit_x)) * ray->wall->width);
    // x = (int)((ray->hit_y - floor(ray->hit_y)) * ray->wall->width);
//	printf("WALL ID %d ray hit y %Lf ray hit x %Lf x %d start cell %d\n", ray->wall->id, ray->hit_y, ray->hit_x ,x, start_cell);
	if (x < 0)
		x = 0;
	if (x >= ray->wall->width)
		x = ray->wall->width - 1;
	i -= ray->wall_start;
	y = i * ray->wall->height / ray->wall_height;
	if (y < 0)
		y = 0;
	if (y >= ray->wall->height)
		y = ray->wall->height - 1;
	// printf("WALL I %d\n", i);
	// printf("WALL ID: %d DISTANCE: %Lf x: %d y: %d\n", ray->wall->id,ray->distance, x, y);
	offset = (y * cub->wall_cub[dir].img->line_len + x * (cub->wall_cub[dir].img->bpp / 8));
	color = *(unsigned int *)(cub->wall_cub[dir].img->addr + offset);
	return (color);
}


void	adding_pix_to_img(t_cub *cub, t_ray *ray)
{

	int	i;
	int	temp;
	int offset;
	unsigned int color;
	
	temp = -1;
	while (++temp < WIDTH)
	{
		i = 0;
		color = cub->data->color_ceiling;
		if (!ray[temp].wall_start)
			ray[temp].wall_start = ray[temp - 1].wall_start;
		while (i < HEIGHT && i < ray[temp].wall_start)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			*(unsigned int *)(cub->img->addr + offset) = color;
			i++;
		}
		if (ray[temp].wall->direction == 'A')
		{
			color = BLACK;
			while (i < HEIGHT && i < ray[temp].wall_end)
			{
				offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
				*(unsigned int *)(cub->img->addr + offset) = color;
				i++;
			}
		}
		else
		{
			while (i < HEIGHT && i < ray[temp].wall_end)
			{
				offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
				color = get_color(&ray[temp], i, cub);
				*(unsigned int *)(cub->img->addr + offset) = color;
				i++;
			}
		}
		color = cub->data->color_floor;
		while (i < HEIGHT)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			*(unsigned int *)(cub->img->addr + offset) = color;
			i++;
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}
