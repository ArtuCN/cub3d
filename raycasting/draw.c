/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:23:00 by artucn            #+#    #+#             */
/*   Updated: 2024/10/08 16:32:40 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	int				offset;
	unsigned int	color;
	int				x;
	int				y;
	int				dir;

	dir = get_dir(ray->wall->direction, ray->wall->door);
	if (ray->wall->direction == 'N' || ray->wall->direction == 'S')
		x = (ray->hit_x - floor(ray->hit_x)) * ray->wall->width;
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
	offset = (y * cub->wall_cub[dir].img->line_len
			+ x * (cub->wall_cub[dir].img->bpp / 8));
	color = *(unsigned int *)(cub->wall_cub[dir].img->addr + offset);
	return (color);
}

void	put_pause(t_cub *cub, int i, int start_y)
{
	int				j;
	int				offset;
	int				text_width;
	unsigned int	color;
	int				start_x;

	j = -1;
	text_width = cub->pause_img->width * 9;
	start_x = (WIDTH - text_width) / 2;
	while (++j < text_width)
	{
		offset = ((start_y + i) * cub->img->line_len
				+ (start_x + j) * (cub->img->bpp / 8));
		color = get_sprite_pixel_color(cub->pause_img, j / 9, i / 9);
		if ((color & 0xFF000000) == 0x00000000)
			*(unsigned int *)(cub->img->addr + offset) = color;
	}
}

void	draw_pause(t_cub *cub)
{
	int	i;
	int	text_height;
	int	start_y;

	i = -1;
	if (cub->pause == 0)
		return ;
	text_height = cub->pause_img->height * 9;
	start_y = (HEIGHT - text_height) / 2;
	while (++i < text_height)
		put_pause(cub, i, start_y);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}

void	adding_pix_to_img(t_cub *cub, t_ray *ray)
{
	int				i;
	int				temp;
	int				offset;
	unsigned int	color;

	temp = -1;
	while (++temp < WIDTH)
	{
		i = 0;
		draw_cealing(&i, ray, temp, cub);
		while (i < HEIGHT && i < ray[temp].wall_end)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			color = get_color(&ray[temp], i, cub);
			*(unsigned int *)(cub->img->addr + offset) = color;
			i++;
		}
		draw_floor(&i, ray, temp, cub);
	}
	drawing_sword(cub);
	mlx_clear_window(cub->mlx, cub->win);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}
