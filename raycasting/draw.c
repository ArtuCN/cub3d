/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:23:00 by artucn            #+#    #+#             */
/*   Updated: 2024/09/20 15:16:15 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// void	draw_this_wall(t_ray *ray, t_cub *cub, int num, int end)
// {
// 	int	temp;
// 	int	x;
// 	t_img	*img;

// 	img = ray[end].wall->img;
// 	if (img != NULL)
// 		img->addr = mlx_get_data_addr(img, &img->bpp, &img->line_len, &img->endian);
// 	if (end - num < 0)
// 		x = 0;
// 	else
// 		x = end - num;
// 	while (++x <= end && x > 0)
// 	{
// 		temp = 0;
// 		while (++temp < ray[x].wall_start && temp < HEIGHT)
// 			my_mlx_pixel_put(cub, x, temp, cub->data->color_ceiling);
// 		my_mlx_pixel_put(cub, x, temp, BLACK);
// 		//if (!is_same(ray, x))
// 		//	mlx_put_image_to_window(cub->mlx, cub->win, ray[x].wall->img, x, ray[x].wall->wall_start);
// 		my_mlx_pixel_put(cub, x, temp, BLACK);
// 		temp = ray[x].wall_end - 1;
// 		while (++temp < HEIGHT)
// 			my_mlx_pixel_put(cub, x, temp, cub->data->color_floor);
// 		my_mlx_pixel_put(cub, x, temp, BLACK);
// 	}
// }

// void	get_column(t_img *column, t_ray *ray, t_wall *wall)
// {	
// 	int i;
// 	int offset;
// 	int	x;
// 	unsigned int color;
	
// 	if (wall->direction == 'A')
// 	{
// 		i = -1;
// 		while (++i < wall->height)
// 			*(unsigned int *)(column->addr + i * column->line_len) = 0;
// 		return ;
// 	}
// 	if (wall->direction == 'N' || wall->direction == 'S')
// 		x = (int)(ray->wall->wall_hit_y * ray->wall->width);
// 	else
// 		x = (int)(ray->wall->wall_hit_x * ray->wall->width);
// 	i = -1;
// 	while (++i < wall->height)
// 	{
// 		offset = (i * wall->img->line_len + (x) * (wall->img->bpp / 8));
// 		color = *(unsigned int *)(wall->img->addr + offset);
//     	*(unsigned int *)(column->addr + i * column->line_len) = color;
// 	}
// }



// void	drawing_rays(t_player *player, t_cub *cub)
// {
// 	t_ray	*ray;
// 	int	i;

// 	i = -1;
// 	//void *tmp;
// 	ray = player->ray;
// 	while(++i < player->num_rays)
// 	{			
//         ray->column_img = mlx_new_image(cub->mlx, 1, ray[i].wall->wall_end - ray[i].wall->wall_start);
//         ray->column_img->addr = mlx_get_data_addr(&ray->column_img->img_ptr,
// 			&ray->column_img->bpp,
//             &ray->column_img->line_len,
// 			&ray->column_img->endian);
// 		get_column(ray->column_img, &ray[i], ray[i].wall);
// 	}
// 	// find_pos_wall(ray, cub);
// 	draw_all(cub, player);
// }

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

unsigned int	get_color(t_wall *wall, int i, t_cub *cub, int temp)
{
	int	offset;
	unsigned int color;
	long double x;
	long double	y;
	char dir;

	dir = wall->direction;
	printf ("PROVA WX WY %Lf %Lf\n", wall->wall_hit_y, wall->wall_hit_x);
	if (dir == 'N' || dir == 'S')
		x = (wall->wall_hit_y);
	else
		x = (wall->wall_hit_x);
	x = map(x, 0, 1, 0, wall->width);
	printf("x = %Lf\n", x);
	y = map(i, cub->player->ray[temp].wall_start, cub->player->ray[temp].wall_end, 0, wall->height);
	offset = (y * cub->wall_cub[get_dir(dir, wall->door)].img->line_len + (x) * (cub->wall_cub[get_dir(dir, wall->door)].img->bpp / 8));
	color = *(unsigned int *)(cub->wall_cub[get_dir(dir, wall->door)].img->addr + offset);
	return (color);
}

void	adding_pix_to_img(t_cub *cub, t_ray *ray)
{
	int	i;
	int	temp;
	int offset;
	unsigned int color;
	
	temp = 0;
	while (++temp < WIDTH)
	{
		i = -1;
		color = cub->data->color_ceiling;
		while (++i < HEIGHT && i < ray[temp].wall_start)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			*(unsigned int *)(cub->img->addr + offset) = color;
		}
		if (ray[temp].wall->direction == 'A')
		{
			color = BLACK;
			while (++i < HEIGHT && i < ray[temp].wall_end)
			{
				offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
				*(unsigned int *)(cub->img->addr + offset) = color;
			}
		}
		else
		{
			while (++i < HEIGHT && i < ray[temp].wall_end)
			{
				offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
				color = get_color(ray[temp].wall, i, cub, temp);
				*(unsigned int *)(cub->img->addr + offset) = color;
			}
		}
		color = cub->data->color_floor;
		while (++i < HEIGHT)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			*(unsigned int *)(cub->img->addr + offset) = color;
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}
