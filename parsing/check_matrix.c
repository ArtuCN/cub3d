/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:18:39 by aconti            #+#    #+#             */
/*   Updated: 2024/08/01 13:35:22 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_cor(char *line)
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

char **copy_map(char **matrix, int g)
{
	char **map;
	int	i;
	int	len;
	
	i = 0;
	len = 0;
	while (matrix[g + len])
		len++;
	map = malloc(sizeof(char *) * len + 1);
	if (!map)
		return (0);
	while (matrix[g])
	{
		map[i] = ft_strdup(matrix[g]);
		i++;
		g++;
	}
	map[i] = NULL;
	return (map);
}

void print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		printf("%s", matrix[i]);
		i++;
	}
	printf("\n");
}

int	check_first_char(char **matrix, t_data *data)
{
	int i;
	int g;

	g = 0;
	i = 0;
	while (matrix[g] && i < 6)
	{
		while (!ft_strncmp(matrix[g], "\n", 1))
			g++;
		if ((matrix[g][0] <= '9' && matrix[g][0] >= '0') || !check_cor(matrix[g]))
			return (printf("map isn't correct1\n"), 0);
		else if (check_cor(matrix[g]))
			i++;
		g++;
	}
	while (!ft_strncmp(matrix[g], "\n", 1))
		g++;
	data->map = copy_map(matrix, g);
	print_matrix(data->map);
	if (!check_map(data->map))
		return (printf("map isn't correct2\n"), 0);
	return (1);
}

int	check_matrix(t_data *data)
{
	if (!check_first_char(data->matrix, data))
		return (0);
	printf("Matrix is correct3\n");
	return (1);
}