/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:17:50 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 16:30:29 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_cealing(int *i, t_ray *ray, int temp, t_cub *cub)
{
	int				offset;
	unsigned int	color;

	(void)ray;
	color = cub->data->color_ceiling;
	if (!ray[temp].wall_start)
		ray[temp].wall_start = ray[temp - 1].wall_start;
	while (*i < HEIGHT && *i < ray[temp].wall_start)
	{
		offset = (*i * cub->img->line_len + temp * (cub->img->bpp / 8));
		*(unsigned int *)(cub->img->addr + offset) = color;
		(*i)++;
	}
}

void	draw_floor(int *i, t_ray *ray, int temp, t_cub *cub)
{
	unsigned int	color;
	int				offset;

	(void)ray;
	color = cub->data->color_floor;
	while (*i < HEIGHT)
	{
		offset = (*i * cub->img->line_len + temp * (cub->img->bpp / 8));
		*(unsigned int *)(cub->img->addr + offset) = color;
		(*i)++;
	}
}
