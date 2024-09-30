/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:09:30 by aconti            #+#    #+#             */
/*   Updated: 2024/09/30 10:11:06 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	len_mat(int fd, t_data *data)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	i = 0;
	while ((line != NULL))
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	data->matrix = malloc(sizeof(char *) * (i + 1));
	if (!data->matrix)
		return (printf("Error\nmalloc failed\n"), 0);
	data->matrix[i] = NULL;
	close(fd);
	return (1);
}

int	put_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	i = 0;
	while (line != NULL)
	{
		data->matrix[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	regular_map(char *name, t_cub *cub)
{
	int	fd;

	cub->data = malloc(sizeof(t_data));
	if (!name)
		return (printf("Error\nno map\n"), 0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nopen failed\n"), 0);
	if (!len_mat(fd, cub->data))
		return (0);
	fd = open(name, O_RDONLY);
	if (!put_map(fd, cub->data))
		return (0);
	close(fd);
	if (!check_matrix(cub->data))
		return (0);
	return (1);
}
