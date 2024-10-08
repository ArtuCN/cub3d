/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:09:30 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 14:31:26 by aconti           ###   ########.fr       */
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
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	data->matrix = malloc(sizeof(char *) * (i + 1));
	if (!data->matrix)
		return (printf("Malloc Failed\n"), 0);
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

int	some_if(char *name, t_cub *cub, int fd)
{
	cub->data = malloc(sizeof(t_data));
	if (!name)
	{
		free(cub->data);
		return (printf("Map Not Found\n"), 0);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		free(cub->data);
		return (printf("Map Not Found\n"), 0);
	}
	if (!len_mat(fd, cub->data))
	{
		free(cub->data);
		return (printf("Empty Map\n"), 0);
	}
	return (1);
}

int	regular_map(char *name, t_cub *cub)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (!some_if(name, cub, fd))
		return (0);
	if (!put_map(fd, cub->data))
	{
		free_matrix(cub->data->matrix);
		free(cub->data->matrix);
		free(cub->data);
		return (printf("Error"), 0);
	}
	close(fd);
	if (!check_matrix(cub->data))
	{
		free(cub->data);
		return (0);
	}
	return (1);
}
