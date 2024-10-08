/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sword.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:13:04 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 15:58:00 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_sprite_pixel_color(t_sword *sword, int x, int y)
{
	int		offset;
	t_img	*sprite_img;

	sprite_img = sword->img;
	if (x < 0 || x >= sword->width || y < 0 || y >= sword->height)
		return (0);
	offset = (y * sprite_img->line_len + x * (sprite_img->bpp / 8));
	return (*(unsigned int *)(sprite_img->addr + offset));
}

void	change_frame(t_cub *cub)
{
	cub->frame++;
	if (cub->frame > 11 && cub->show_sword == 1)
		cub->frame = 0;
	else if (cub->frame > 3 && cub->show_sword == 2)
	{
		cub->frame = 0;
		cub->show_sword = 1;
	}
}

void	sword2(unsigned int color, t_cub *cub, int *x, int *y)
{
	int	dy;
	int	dx;
	int	offset;

	dy = 0;
	if (color != TRANSPARENT_COLOR)
	{
		while (dy < SPRITE_Y)
		{
			dx = 0;
			while (dx < SPRITE_X)
			{
				offset = ((*y + dy) * cub->img->line_len
						+ (*x + dx) * (cub->img->bpp / 8));
				*(unsigned int *)(cub->img->addr + offset) = color;
				dx++;
			}
			dy++;
		}
	}
}

void	sword(t_cub *cub, int *x, int *y, int i)
{
	int				j;
	unsigned int	color;
	int				start_x;
	int				start_y;

	start_y = HEIGHT - (cub->sword->height * SPRITE_Y);
	start_x = WIDTH - (cub->sword->width * SPRITE_X);
	j = -1;
	while (++j < cub->sword->width)
	{
		if (cub->show_sword == 2)
			color = get_sprite_pixel_color(&cub->hit[cub->frame], j, i);
		else
			color = get_sprite_pixel_color(&cub->sword[cub->frame], j, i);
		*x = start_x + (j * SPRITE_X);
		*y = start_y + (i * SPRITE_Y);
		sword2(color, cub, x, y);
	}
}

void	drawing_sword(t_cub *cub)
{
	int	x;
	int	y;
	int	i;

	if (!cub->show_sword && cub->change == 0)
		return ;
	i = 0;
	while (i < cub->sword->height)
	{
		sword(cub, &x, &y, i);
		i++;
	}
	change_frame(cub);
}
