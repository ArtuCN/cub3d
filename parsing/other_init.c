/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:35:15 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 18:42:38 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_null_data(t_data *data)
{
	if (!data->north || !data->south || !data->west
		|| !data->east || !data->floor
		|| !data->ceiling)
		return (0);
	if (ft_strncmp(data->north, "NO ./../textures/wall_n.xpm\n",
			ft_strlen(data->north))
		|| ft_strncmp(data->south, "SO ./../textures/wall_s.xpm\n",
			ft_strlen(data->south))
		|| ft_strncmp(data->west, "WE ./../textures/wall_w.xpm\n",
			ft_strlen(data->east))
		|| ft_strncmp(data->east, "EA ./../textures/wall_e.xpm\n",
			ft_strlen(data->west)))
		return (0);
	return (1);
}

int	get_cor(t_data *data)
{
	int	i;

	i = 0;
	while (data->matrix[i])
	{
		if (!ft_strncmp(data->matrix[i], "NO ", 3))
			data->north = ft_strdup(data->matrix[i]);
		else if (!ft_strncmp(data->matrix[i], "SO ", 3))
			data->south = ft_strdup(data->matrix[i]);
		else if (!ft_strncmp(data->matrix[i], "WE ", 3))
			data->west = ft_strdup(data->matrix[i]);
		else if (!ft_strncmp(data->matrix[i], "EA ", 3))
			data->east = ft_strdup(data->matrix[i]);
		else if (!ft_strncmp(data->matrix[i], "F ", 2))
			data->floor = ft_strdup(data->matrix[i]);
		else if (!ft_strncmp(data->matrix[i], "C ", 2))
			data->ceiling = ft_strdup(data->matrix[i]);
		i++;
	}
	if (!check_null_data(data))
		return (0);
	return (1);
}

int	data_max(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (j > data->max_x)
				data->max_x = j;
			j++;
		}
		i++;
	}
	data->max_y = i;
	if (data->max_x < 3 || data->max_y < 3)
		return (0);
	return (1);
}
