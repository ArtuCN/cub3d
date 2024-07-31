/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:09:30 by aconti            #+#    #+#             */
/*   Updated: 2024/07/31 17:29:04 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int len_mat(int fd, t_cub *cub)
{
	int		i;
	char *line;

	i = 0;
	while (((line = get_next_line(fd)) != NULL))
	{
		free(line);
		i++;
	}
	cub->map = malloc(sizeof(char *) * i + 1);
	if (!cub->map)
		return (printf("Error\nmalloc failed\n"), 0);
	close(fd);
	return (1);
}

int	put_map(int fd, t_cub *cub)
{
	char *line;
	int i;
	
	i = 0;
	while (((line = get_next_line(fd)) != NULL))
	{
		cub->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

int regular_map(char *name, t_cub *cube)
{
	int fd;

	if (!name)
		return (printf("Error\nno map\n"), 0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nopen failed\n"), 0);
	if (!len_mat(fd, cube))
		return (0);
	fd = open(name, O_RDONLY);
	if (!put_map(fd, cube))
		return (1);
	close(fd);
	if (!check_map(cube))
		return (printf("Error\nmap not regular\n"), 0);
	return (1);
}
