/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:08:44 by aconti            #+#    #+#             */
/*   Updated: 2024/10/07 15:36:15 by aconti           ###   ########.fr       */
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

void free_img_array(void *mlx_ptr, t_sword *img_array, int size)
{
    int i;

    if (img_array)
	{
        for (i = 0; i < size; i++) {
            if (img_array[i].img) {
                mlx_destroy_image(mlx_ptr, img_array[i].img);
                img_array[i].img = NULL;
            }
        }
        free(img_array);
        img_array = NULL;
    }
}

void	free_img(t_cub *cub)
{
	int	i;
	
	i = -1;
	// while (++i < 5)
	// {
	// 	if (cub->wall_cub[i].img)
	// 	{
	// 		if (cub->wall_cub[i].img->img_ptr)
	// 		{
	// 			printf("Destroying image %d\n", i);
	// 			mlx_destroy_image(cub->mlx, cub->wall_cub[i].img->img_ptr);
	// 			cub->wall_cub[i].img->img_ptr = NULL;
	// 		}
	// 		free(cub->wall_cub[i].img);
	// 		cub->wall_cub[i].img = NULL;
	// 	}
	// }
	free(cub->wall_cub);
	i = 0;
	while (i < 12)
	{
		if (cub->sword[i].img) // Verifica se l'immagine è stata allocata
		{
			if (cub->sword[i].img->img_ptr) // Verifica se l'immagine ha un puntatore valido
			{
				mlx_destroy_image(cub->mlx, cub->sword[i].img->img_ptr);
				cub->sword[i].img->img_ptr = NULL;
			}
			free(cub->sword[i].img->img_ptr); // Libera correttamente
			cub->sword[i].img = NULL; // Imposta il puntatore a NULL per evitare doppia liberazione
		}
		i++;
	}

	i = 0;
	while (i < 4)
	{
		if (cub->hit[i].img) // Aggiungi controllo per cub->hit[i].img
		{
			// if (cub->hit[i].img->img_ptr) // Verifica se l'immagine ha un puntatore valido
			// {
			// 	mlx_destroy_image(cub->mlx, cub->hit[i].img->img_ptr);
			// 	cub->hit[i].img->img_ptr = NULL;
			// }
			free(cub->hit[i].img->img_ptr); // Libera correttamente
			cub->hit[i].img = NULL; // Imposta il puntatore a NULL
		}
		i++;
	}
}



void	free_cub(t_cub *cub)
{
	t_data	*data;

	data = cub->data;
	free_matrix(data->matrix);
	free_matrix(data->map);
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	free(data->ceiling);
	free(data->floor);
	free_img(cub);
	free_wall(cub->player);
	free(cub->player->ray);
	free(cub->player);
	free(data);
	free(cub->wall_cub);
	free(cub->img);
}
