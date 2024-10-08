/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:23:06 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 13:24:21 by aconti           ###   ########.fr       */
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

void	free_data(t_cub *cub)
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
	free(data);
}
