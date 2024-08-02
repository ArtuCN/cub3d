/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:08:44 by aconti            #+#    #+#             */
/*   Updated: 2024/08/02 18:24:48 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_matrix(char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		mat[i] = NULL;
		i++;
	}
	free(mat);
}

void	free_cub(t_cub *cub)
{
	t_data *data;

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
	free(data);
}
