/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:48:25 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 16:27:53 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	adding_img(t_cub *cub, int i)
{
	cub->wall_cub[i].img = malloc(sizeof(t_img));
	get_texture(cub, i);
	if (cub->wall_cub[i].img && cub->wall_cub[i].img->img_ptr)
	{
		cub->wall_cub[i].img->addr = mlx_get_data_addr
			(cub->wall_cub[i].img->img_ptr, &(cub->wall_cub[i].img->bpp),
				&(cub->wall_cub[i].img->line_len),
				&(cub->wall_cub[i].img->endian));
	}
}

void	adding_sprite(t_cub *cub, int i)
{
	cub->sword[i].img = malloc(sizeof(t_img));
	if (i >= 0 && i <= 4)
		get_sprites0_4(cub, i);
	else if (i >= 5 && i <= 8)
		get_sprites5_8(cub, i);
	else if (i >= 9 && i <= 12)
		get_sprites9_12(cub, i);
	if (cub->sword[i].img && cub->sword[i].img->img_ptr)
	{
		cub->sword[i].img->addr = mlx_get_data_addr
			(cub->sword[i].img->img_ptr, &(cub->sword[i].img->bpp),
				&(cub->sword[i].img->line_len),
				&(cub->sword[i].img->endian));
	}
}

void	adding_hit(t_cub *cub, int i)
{
	cub->hit[i].img = malloc(sizeof(t_img));
	if (i == 0)
		cub->hit[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/hit0.xpm", &cub->hit[i].width,
				&cub->hit[i].height);
	else if (i == 1)
		cub->hit[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/hit1.xpm", &cub->hit[i].width,
				&cub->hit[i].height);
	else if (i == 2)
		cub->hit[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/hit2.xpm", &cub->hit[i].width,
				&cub->hit[i].height);
	else if (i == 3)
		cub->hit[i].img->img_ptr = mlx_xpm_file_to_image(cub->mlx,
				"textures/hit3.xpm", &cub->hit[i].width,
				&cub->hit[i].height);
	if (cub->hit[i].img && cub->hit[i].img->img_ptr)
		cub->hit[i].img->addr = mlx_get_data_addr
			(cub->hit[i].img->img_ptr, &(cub->hit[i].img->bpp),
				&(cub->hit[i].img->line_len),
				&(cub->hit[i].img->endian));
}

void	get_pause(t_cub *cub)
{
	cub->pause_img = malloc(sizeof(t_sword));
	cub->pause_img->img = malloc(sizeof(t_img));
	if (!cub->pause_img)
	{
		printf("Failed to allocate memory for pause_img\n");
		return ;
	}
	cub->pause_img->img->img_ptr = mlx_xpm_file_to_image
		(cub->mlx, "textures/pause.xpm", &cub->pause_img->width,
			&cub->pause_img->height);
	if (!cub->pause_img->img)
	{
		printf("Failed to load image for pause\n");
		free(cub->pause_img);
		return ;
	}
	if (cub->pause_img->img && cub->pause_img->img->img_ptr)
	{
		cub->pause_img->img->addr = mlx_get_data_addr
			(cub->pause_img->img->img_ptr, &(cub->pause_img->img->bpp),
				&(cub->pause_img->img->line_len),
				&(cub->pause_img->img->endian));
	}
}

void	adding_wall(t_cub *cub)
{
	int	i;

	cub->show_sword = 1;
	cub->change = 0;
	cub->pause = 0;
	cub->frame = 0;
	cub->wall_cub = malloc(sizeof(t_wall_cub) * 5);
	i = -1;
	while (++i < 5)
		adding_img(cub, i);
	i = -1;
	cub->sword = malloc(sizeof(t_sword) * 12);
	while (++i < 12)
		adding_sprite(cub, i);
	cub->hit = malloc(sizeof(t_sword) * 4);
	i = -1;
	while (++i < 4)
		adding_hit(cub, i);
	get_pause(cub);
}
