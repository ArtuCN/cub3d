/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:14:11 by aconti            #+#    #+#             */
/*   Updated: 2024/08/07 12:25:45 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_player_pos(t_cub *cub, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->player_dir)
			{
				cub->player->x = j;
				cub->player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	player_init(t_cub *cub)
{
	t_player *player;
	player = malloc(sizeof(t_player));
	
	cub->player = player;
	if (!cub->player)
	{
		free(cub->mlx);
		free(cub->win);
		free(cub->img);
		return ;
	}
	find_player_pos(cub, cub->data);
}
