/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:23:00 by artucn            #+#    #+#             */
/*   Updated: 2024/10/02 15:03:20 by aconti           ###   ########.fr       */
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
	if (ray->wall->direction == 'N' || ray->wall->direction ==  'S')
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
	offset = (y * cub->wall_cub[dir].img->line_len + x * (cub->wall_cub[dir].img->bpp / 8));
	color = *(unsigned int *)(cub->wall_cub[dir].img->addr + offset);
	return (color);
}


unsigned int get_sprite_pixel_color(t_sword *sword, int x, int y)
{
	int offset;
	t_img *sprite_img;

	sprite_img = sword->img;
	
	// Controlla che x e y siano all'interno dei limiti dello sprite
	if (x < 0 || x >= sword->width || y < 0 || y >= sword->height)
		return (0);  // Restituisci un colore trasparente o 0 se fuori dai limiti

	
	offset = (y * sprite_img->line_len + x * (sprite_img->bpp / 8));

	return (*(unsigned int *)(sprite_img->addr + offset));
}

void	drawing_sword(t_cub *cub)
{
	int x;
	int y;
	int i;
	int j;
	static int current_frame = 0;
	int offset;
	unsigned int color;

	// Posizione in basso a destra
	int start_x = WIDTH - (cub->sword->width * SPRITE_X);  // Moltiplica la larghezza per 5
	int start_y = HEIGHT - (cub->sword->height * SPRITE_Y); // Moltiplica l'altezza per 5
	
	i = 0;
	while (i < cub->sword->height)
	{
		j = 0;
		while (j < cub->sword->width)
		{
			color = get_sprite_pixel_color(&cub->sword[current_frame], j, i);		
			x = start_x + (j * SPRITE_X);
			y = start_y + (i * SPRITE_Y);

			if (color != TRANSPARENT_COLOR)
			{
				for (int dy = 0; dy < SPRITE_Y; dy++)
				{
					for (int dx = 0; dx < SPRITE_X; dx++)
					{
						offset = ((y + dy) * cub->img->line_len + (x + dx) * (cub->img->bpp / 8));
						*(unsigned int *)(cub->img->addr + offset) = color;
					}
				}
			}
			j++;
		}
		i++;
	}
	current_frame++;
	if (current_frame >= 6)
		current_frame = 0;
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
		while (i < HEIGHT && i < ray[temp].wall_end)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			color = get_color(&ray[temp], i, cub);
			*(unsigned int *)(cub->img->addr + offset) = color;
			i++;
		}
		color = cub->data->color_floor;
		while (i < HEIGHT)
		{
			offset = (i * cub->img->line_len + temp * (cub->img->bpp / 8));
			*(unsigned int *)(cub->img->addr + offset) = color;
			i++;
		}
	}
	drawing_sword(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}
