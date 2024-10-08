/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:25:14 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 18:42:52 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	rgb_to_hex(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

int	add_num(char *tmp, int *i)
{
	int	num;
	int	count;

	count = *i;
	num = 0;
	while (tmp[*i] != ',' && tmp[*i] != '\n' && tmp[*i] != '\0')
	{
		num = num * 10 + (tmp[*i] - '0');
		(*i)++;
	}
	if (count == *i)
		return (-1);
	if (tmp[*i] == ',')
		(*i)++;
	return (num);
}

int	add_ceiling(t_data *data)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 2;
	red = add_num(data->ceiling, &i);
	green = add_num(data->ceiling, &i);
	blue = add_num(data->ceiling, &i);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
	{
		printf("Error\nInvalid color\n");
		return (0);
	}
	data->color_ceiling = rgb_to_hex(red, green, blue);
	return (1);
}

int	add_floor(t_data *data)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 2;
	red = add_num(data->floor, &i);
	green = add_num(data->floor, &i);
	blue = add_num(data->floor, &i);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
	{
		printf("Error\nInvalid color\n");
		return (0);
	}
	data->color_floor = rgb_to_hex(red, green, blue);
	return (1);
}

int	init_data(t_data *data)
{
	if (!get_cor(data))
		return (0);
	if (!add_ceiling(data) || !add_floor(data))
		return (0);
	data->max_x = 0;
	data->max_y = 0;
	if (!data_max(data))
		return (0);
	return (1);
}
