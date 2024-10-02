/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:48:25 by aconti            #+#    #+#             */
/*   Updated: 2024/10/02 14:58:48 by aconti           ###   ########.fr       */
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
		&(img->bpp),
		&(img->line_len),
		&(img->endian));
}


void	adding_sprite(t_cub *cub, int i)
{
	if (i == 0)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_0.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 1)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_1.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 2)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_2.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 3)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_3.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 4)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_4.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 5)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_5.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 6)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_6.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 7)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_7.xpm", &cub->sword[i].width, &cub->sword[i].height);
	printf("i = %d\n", i);
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
	i = -1;
	cub->sword = malloc(sizeof(t_sword) * 8);
	while (++i < 8)
	{
		printf("i = %d\n", i);
		adding_sprite(cub, i);
		img_info(cub->sword[i].img);
	}
}
