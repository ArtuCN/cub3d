/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:23:00 by artucn            #+#    #+#             */
/*   Updated: 2024/09/25 13:06:12 by aconti           ###   ########.fr       */
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
	
	dir = get_dir(ray->wall->direction, ray->wall->door);
	if (dir == 'N' || dir == 'S')
    x = (int)((ray->hit_x - floor(ray->hit_x)) * ray->wall->width);
else
    x = (int)((ray->hit_y - floor(ray->hit_y)) * ray->wall->width);

	if (x < 0)
		x = 0;
	if (x >= ray->wall->width)
		x = ray->wall->width - 1;
	y = ((i - ray->wall_start) * ray->wall->height) / (ray->wall_end - ray->wall_start);
	if (y < 0)
		y = 0;
	if (y >= ray->wall->height)
		y = ray->wall->height - 1;
	offset = (y * cub->wall_cub[dir].img->line_len + x * (cub->wall_cub[dir].img->bpp / 8));
	color = *(unsigned int *)(cub->wall_cub[dir].img->addr + offset);
	//printf("Ray: %d, wall_start: %d, wall_end: %d, i: %d, y: %d, tex_x: %d, tex_y: %d\n", 
        //temp,  (int)cub->player->ray[temp].wall_start,  (int)cub->player->ray[temp].wall_end, i, y, x, y);
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
