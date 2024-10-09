/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:18:39 by aconti            #+#    #+#             */
/*   Updated: 2024/10/09 14:44:23 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_coord(t_data *data)
{
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->west)
		free(data->west);
	if (data->east)
		free(data->east);
	if (data->ceiling)
		free(data->ceiling);
	if (data->floor)
		free(data->floor);
}

int	check_cor(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	else if (!ft_strncmp(line, "SO ", 3))
		return (1);
	else if (!ft_strncmp(line, "WE ", 3))
		return (1);
	else if (!ft_strncmp(line, "EA ", 3))
		return (1);
	else if (!ft_strncmp(line, "F ", 2))
		return (1);
	else if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

void	copy_map(char **matrix, int g, t_data *data)
{
	char	**map;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (matrix[g + len])
		len++;
	map = malloc(sizeof(char *) * (len + 1));
	while (matrix[g])
	{
		map[i] = ft_strdup(matrix[g]);
		i++;
		g++;
	}
	map[i] = NULL;
	data->map = map;
}

int	check_first_char(char **matrix, t_data *data)
{
	int	i;
	int	g;

	g = 0;
	i = 0;
	while (matrix[g] && i < 6)
	{
		while (!ft_strncmp(matrix[g], "\n", 1))
			g++;
		if ((matrix[g][0] <= '9' && matrix[g][0] >= '0')
			|| !check_cor(matrix[g]))
			return (0);
		else if (check_cor(matrix[g]))
			i++;
		g++;
	}
	while (matrix[g] && !ft_strncmp(matrix[g], "\n", 1)
		&& !ft_strncmp(matrix[g], "\0", 1))
		g++;
	copy_map(matrix, g, data);
	if (!check_map(data->map, data))
		return (0);
	return (1);
}

int	check_matrix(t_data *data)
{
	if (!check_first_char(data->matrix, data))
	{
		free_matrix(data->matrix);
		if (data->map)
			free_matrix(data->map);
		return (printf("Map Info Are Not Correct\n"), 0);
	}
	if (!init_data(data))
	{
		free_coord(data);
		free_matrix(data->matrix);
		if (data->map)
			free_matrix(data->map);
		return (printf("Map is Not Correct\n"), 0);
	}
	return (1);
}
