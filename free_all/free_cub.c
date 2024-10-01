/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:08:44 by aconti            #+#    #+#             */
/*   Updated: 2024/10/01 17:08:24 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		mat[i] = NULL;
		i++;
	}
	free(mat);
}



void	free_wall(t_player *player)
{
	int	i;

	i = 0;
	while (i < player->num_rays)
	{
		
		if (player->ray[i].wall != player->ray[i + 1].wall && i < player->num_rays)
			free(player->ray[i].wall);
		i++;
	}

}

void	free_img(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(cub->mlx, cub->wall_cub[i].img->img_ptr);
		i++;
	}
}



void	free_cub(t_cub *cub)
{
	t_data	*data;

	data = cub->data;
	free(cub->img);
	free_matrix(data->matrix);
	free_matrix(data->map);
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	free(data->ceiling);
	free(data->floor);
	free_wall(cub->player);
	free(cub->player->ray);
	free(cub->player);
	free(data);
	//free_img(cub); MANDA IN SIGSEV
}
