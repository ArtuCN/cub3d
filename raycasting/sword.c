/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sword.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:13:04 by aconti            #+#    #+#             */
/*   Updated: 2024/10/02 17:03:33 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sword_hit(t_cub *cub, int sprite)
{
	int x;
	int y;
	int i;
	int j;
	int offset;
	unsigned int color;

	// Posizione in basso a destra
	int start_x = WIDTH - (cub->sword->width * SPRITE_X);  // Moltiplica la larghezza per 5
	int start_y = HEIGHT - (cub->sword->height * SPRITE_Y); // Moltiplica l'altezza per 5
	if (sprite == 7)
	{
		cub->show_sword = 1;
		return ;
	}
	while (i < cub->sword->height)
	{
		j = 0;
		while (j < cub->sword->width)
		{
			color = get_sprite_pixel_color(&cub->sword[sprite], j, i);		
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
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
	usleep(10);
	sword_hit(cub, sprite++);	
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
	if (!cub->show_sword)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
		return ;
	}
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
		current_frame = 1;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}
