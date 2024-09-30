/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:48:25 by aconti            #+#    #+#             */
/*   Updated: 2024/09/20 12:38:45 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	adding_img(t_cub *cub, int i)
{
	if (i == DOOR)
		cub->wall_cub[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/door.xpm", &cub->wall_cub[i].width, &cub->wall_cub[i].height);
	else if (i == WALL_N)
		cub->wall_cub[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/wall_n.xpm", &cub->wall_cub[i].width, &cub->wall_cub[i].height);
	else if (i == WALL_S)
		cub->wall_cub[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/wall_s.xpm", &cub->wall_cub[i].width, &cub->wall_cub[i].height);
	else if (i == WALL_W)
		cub->wall_cub[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/wall_w.xpm", &cub->wall_cub[i].width, &cub->wall_cub[i].height);
	else if (i == WALL_E)
		cub->wall_cub[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/wall_e.xpm", &cub->wall_cub[i].width, &cub->wall_cub[i].height);
}

void	img_info(t_img *img)
{
	img->addr = mlx_get_data_addr(&img->img_ptr,
		&img->bpp,
		&img->line_len,
		&img->endian);
}

void	adding_wall(t_cub *cub)
{
	int i;

	cub->wall_cub = malloc(sizeof(t_wall_cub) * 5);
	i = -1;
	while (++i < 5)
	{
		adding_img(cub, i);
		img_info(cub->wall_cub[i].img);
	}
}