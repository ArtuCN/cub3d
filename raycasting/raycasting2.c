/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:02 by aconti            #+#    #+#             */
/*   Updated: 2024/09/25 17:34:07 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void	get_w_h(t_ray *ray, t_cub *cub)
{
	if (ray->wall->direction == 'D')
	{
		ray->wall->width = cub->wall_cub[DOOR].width;
		ray->wall->height = cub->wall_cub[DOOR].height;
	}
	else if (ray->wall->direction == 'N')
	{
		ray->wall->width = cub->wall_cub[WALL_N].width;
		ray->wall->height = cub->wall_cub[WALL_N].height;
	}
	else if (ray->wall->direction == 'S')
	{
		ray->wall->width = cub->wall_cub[WALL_S].width;
		ray->wall->height = cub->wall_cub[WALL_S].height;
	}
	else if (ray->wall->direction == 'E')
	{
		ray->wall->width = cub->wall_cub[WALL_E].width;
		ray->wall->height = cub->wall_cub[WALL_E].height;
	}
	else if (ray->wall->direction == 'W')
	{
		ray->wall->width = cub->wall_cub[WALL_W].width;
		ray->wall->height = cub->wall_cub[WALL_W].height;
	}
}
