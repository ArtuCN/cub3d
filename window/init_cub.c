/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:48:25 by aconti            #+#    #+#             */
/*   Updated: 2024/10/04 16:46:48 by adonato          ###   ########.fr       */
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
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_01.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 2)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_02.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 3)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_03.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 4)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_04.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 5)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_05.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 6)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_06.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 7)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_07.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 8)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_08.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 9)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_09.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 10)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_10.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 11)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_11.xpm", &cub->sword[i].width, &cub->sword[i].height);
	else if (i == 12)
		cub->sword[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/sprite_12.xpm", &cub->sword[i].width, &cub->sword[i].height);
}

void	adding_hit(t_cub *cub, int i)
{
	if (i == 0)
		cub->hit[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/hit0.xpm", &cub->hit[i].width, &cub->hit[i].height);
	else if (i == 1)
		cub->hit[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/hit1.xpm", &cub->hit[i].width, &cub->hit[i].height);
	else if (i == 2)
		cub->hit[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/hit2.xpm", &cub->hit[i].width, &cub->hit[i].height);
	else if (i == 3)
		cub->hit[i].img = mlx_xpm_file_to_image(cub->mlx, "textures/hit3.xpm", &cub->hit[i].width, &cub->hit[i].height);
}

void	adding_wall(t_cub *cub)
{
	int i;

	cub->show_sword = 1;
	cub->change = 0;
	cub->pause = 0;
	cub->wall_cub = malloc(sizeof(t_wall_cub) * 5);
	i = -1;
	while (++i < 5)
	{
		adding_img(cub, i);
		img_info(cub->wall_cub[i].img);
	}
	i = -1;
	cub->sword = malloc(sizeof(t_sword) * 12);
	while (++i < 12)
	{
		adding_sprite(cub, i);
		img_info(cub->sword[i].img);
	}
	cub->hit = malloc(sizeof(t_sword) * 4);
	i = -1;
	while (++i < 4)
	{
		adding_hit(cub, i);
		img_info(cub->hit[i].img);
	}
}
