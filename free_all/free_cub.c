/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:08:44 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 13:24:37 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_wall(t_player *player)
{
	int		i;
	int		j;
	bool	*freed_walls;

	i = -1;
	freed_walls = (bool *)malloc(player->num_rays * sizeof(bool));
	if (!freed_walls)
		return ;
	while (++i < player->num_rays)
		freed_walls[i] = false;
	i = -1;
	while (++i < player->num_rays)
	{
		if (!freed_walls[i])
		{
			free(player->ray[i].wall);
			j = i - 1;
			while (++j < player->num_rays)
			{
				if (player->ray[j].wall == player->ray[i].wall)
					freed_walls[j] = true;
			}
		}
	}
	free(freed_walls);
}

void	free_img_array(void *mlx_ptr, t_sword *img_array, int size)
{
	int	i;

	i = 0;
	if (img_array)
	{
		while (i < size)
		{
			if (img_array[i].img)
			{
				mlx_destroy_image(mlx_ptr, img_array[i].img);
				img_array[i].img = NULL;
			}
			i++;
		}
		free(img_array);
		img_array = NULL;
	}
}

void	clean_images(t_sword *images, void *mlx, int size)
{
	int	i;

	if (images)
	{
		i = 0;
		while (i < size)
		{
			if (images[i].img)
			{
				if (images[i].img->img_ptr)
				{
					mlx_destroy_image(mlx, images[i].img->img_ptr);
					images[i].img->img_ptr = NULL;
				}
				free(images[i].img);
				images[i].img = NULL;
			}
			i++;
		}
		free(images);
		images = NULL;
	}
}

void	free_img(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->wall_cub)
	{
		while (++i < 5)
		{
			if (cub->wall_cub[i].img)
			{
				if (cub->wall_cub[i].img->img_ptr)
				{
					mlx_destroy_image(cub->mlx, cub->wall_cub[i].img->img_ptr);
					cub->wall_cub[i].img->img_ptr = NULL;
				}
				free(cub->wall_cub[i].img);
				cub->wall_cub[i].img = NULL;
			}
		}
		free(cub->wall_cub);
	}
	i = 0;
	clean_images(cub->sword, cub->mlx, 12);
	clean_images(cub->hit, cub->mlx, 4);
}

void	free_cub(t_cub *cub)
{
	free_data(cub);
	free_wall(cub->player);
	free(cub->player->ray);
	free(cub->player);
	free_img(cub);
	if (cub->pause_img && cub->pause_img->img && cub->pause_img->img->img_ptr)
	{
		mlx_destroy_image(cub->mlx, cub->pause_img->img->img_ptr);
		free(cub->pause_img->img);
		free(cub->pause_img);
	}
	mlx_destroy_image(cub->mlx, cub->img->img_ptr);
	free(cub->img);
	while (cub->win)
	{
		if (cub->win)
			mlx_destroy_window(cub->mlx, cub->win);
		cub->win = NULL;
	}
	mlx_destroy_display(cub->mlx);
	free (cub->mlx);
}
