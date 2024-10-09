/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:46 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 16:26:58 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_sprites0_4(t_cub *cub, int i)
{
	if (i == 0)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_0.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 1)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_01.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 2)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_02.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 3)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_03.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 4)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_04.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
}

void	get_sprites5_8(t_cub *cub, int i)
{
	if (i == 5)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_05.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 6)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_06.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 7)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_07.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 8)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_08.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
}

void	get_sprites9_12(t_cub *cub, int i)
{
	if (i == 9)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_09.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 10)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_10.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 11)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_11.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
	else if (i == 12)
		cub->sword[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/sprite_12.xpm", &cub->sword[i].width,
				&cub->sword[i].height);
}

void	get_texture(t_cub *cub, int i)
{
	if (i == DOOR)
		cub->wall_cub[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/door.xpm", &cub->wall_cub[i].width,
				&cub->wall_cub[i].height);
	else if (i == WALL_N)
		cub->wall_cub[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/wall_n.xpm", &cub->wall_cub[i].width,
				&cub->wall_cub[i].height);
	else if (i == WALL_S)
		cub->wall_cub[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/wall_s.xpm", &cub->wall_cub[i].width,
				&cub->wall_cub[i].height);
	else if (i == WALL_W)
		cub->wall_cub[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/wall_w.xpm", &cub->wall_cub[i].width,
				&cub->wall_cub[i].height);
	else if (i == WALL_E)
		cub->wall_cub[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/wall_e.xpm", &cub->wall_cub[i].width,
				&cub->wall_cub[i].height);
}
