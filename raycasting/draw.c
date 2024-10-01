/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:23:00 by artucn            #+#    #+#             */
/*   Updated: 2024/10/01 15:47:45 by aconti           ###   ########.fr       */
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

// x : 0.5 = c 64
// x : end-start = c : 64


unsigned int	get_color(t_ray *ray, int i, t_cub *cub)
{
	int	offset;
	unsigned int color;
	int x;
	int	y;
	int dir;


	dir = get_dir(ray->wall->direction, ray->wall->door);
	if (dir == 'N' || dir == 'S')
	{
		x = (ray->hit_x - floor(ray->hit_x)) * ray->wall->width;
	}
	else
		x = (ray->hit_y - floor(ray->hit_y)) * ray->wall->width;
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

void	wall_draw_info(t_cub *cub, t_ray *ray)
{
	// int	width_screen;
	// int start_wall;
	// int end_wall;
	// width_screen = -1;
	// start_wall = 0;
	// end_wall = 1;
	// while (++width_screen < WIDTH)
	// {
	// 	if (!is_same(cub, ray, width_screen))
	// 	{
	// 		if (cub->num_walls != 1 && width_screen == 0)
	// 			continue;
	// 		if (end_wall >= WIDTH)
	// 			end_wall = WIDTH - 1;
	// 		ray[width_screen].wall->first_pix_on_screen = start_wall;
	// 		ray[width_screen].wall->last_pix_on_screen = end_wall;
	// 		ray[width_screen].wall->widht_pix_on_screen = end_wall - start_wall;
	// 		printf("TROVATO start_wall = %d\n", start_wall);
	// 		printf("TROVATO end_wall = %d\n", end_wall);
	// 		printf("DIR = %c\n", ray[width_screen].wall->direction);
	// 		start_wall = end_wall + 1;
	// 	}
	// 	if (ray[width_screen].wall->direction == 'N' || ray[width_screen].wall->direction == 'S')
	// 		printf("hit_x = %Lf\n", ray[width_screen].hit_x);
	// 	else
	// 		printf("hit_y = %Lf\n", ray[width_screen].hit_y);
	// 	printf("CHAR = %c y = %Lf x = %Lf\n", cub->data->map[(int)ray[width_screen].y][(int)ray[width_screen].x], ray[width_screen].y, ray[width_screen].x);
	// 	end_wall++;
	// }
	// printf("TROVATO start_wall = %d\n", start_wall);
	// printf("TROVATO end_wall = %d\n", end_wall);
	adding_pix_to_img(cub, ray);
}