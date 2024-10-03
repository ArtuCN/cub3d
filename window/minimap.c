/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:22:01 by aconti            #+#    #+#             */
/*   Updated: 2024/10/03 19:15:35 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define SCALE_FACTOR 0.5

int draw_square(t_cub *cub, int x, int y, unsigned int color)
{
    int i;
    int j;
    int player_minimap_x = cub->player->x * SCALE_FACTOR;
    int player_minimap_y = cub->player->y * SCALE_FACTOR;
    int offset_x = player_minimap_x - (MINIMAP_WIDTH * SCALE_FACTOR) / 2;
    int offset_y = player_minimap_y - (MINIMAP_HEIGHT * SCALE_FACTOR) / 2;
    int minimap_x = x * (TXT_SIZE * SCALE_FACTOR) - offset_x + MINIMAP_X;
    int minimap_y = y * (TXT_SIZE * SCALE_FACTOR) - offset_y + MINIMAP_Y;

    j = minimap_y;
    while (j <= minimap_y + (TXT_SIZE * SCALE_FACTOR))
    {
        i = minimap_x;
        while (i <= minimap_x + (TXT_SIZE * SCALE_FACTOR))
        {
            if ((i == (int)minimap_x) || (j == (int)minimap_y))
                my_mlx_pixel_put(cub, i, j, BLACK);
            else
                my_mlx_pixel_put(cub, i, j, color);
            i++;
        }
        j++;
    }
    return (1);
}

int is_wall(long double x, long double y, t_cub *cub)
{
    long double j;
    long double i;

    if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
        return (1);
    j = (y / TXT_SIZE);
    i = (x / TXT_SIZE);
    if (cub->data->map[(int)j][(int)i] == '1'
        || cub->data->map[(int)j][(int)i] == '\n'
        || !cub->data->map[(int)j][(int)i]
        || cub->data->map[(int)j][(int)i] == 'D')
        return (1);
    return (0);
}

void draw_rays_minimap(t_cub *cub, int x, int y)
{
    int i;
    long double temp_ang;
    double minimap_x;
    double minimap_y;
    temp_ang = (long double)(cub->player->angle - 29);
    while (temp_ang <= cub->player->angle + 30)
    {
        i = -1;
        minimap_x = x * SCALE_FACTOR - cub->data->offset_x + MINIMAP_X;
        minimap_y = y * SCALE_FACTOR - cub->data->offset_y + MINIMAP_Y;
        while (++i <= 10)
        {
            minimap_x += 5 * cos(temp_ang * PI / 180);
            minimap_y += 5 * sin(temp_ang * PI / 180);
            if ((int)minimap_x < 0 || (int)minimap_y < 0 || (int)minimap_x >= MINIMAP_WIDTH
                || (int)minimap_y >= MINIMAP_HEIGHT 
                || is_wall(minimap_x + cub->data->offset_x, minimap_y + cub->data->offset_y, cub))
                break;
            else
                my_mlx_pixel_put(cub, minimap_x, minimap_y, RED);
        }
        temp_ang += cub->player->increment;
    }
}

void draw_player(t_cub *cub, int x, int y, unsigned int color)
{
    int i;
    int j;

    cub->data->offset_x = x * SCALE_FACTOR - (MINIMAP_WIDTH * SCALE_FACTOR) / 2;
    cub->data->offset_y = y * SCALE_FACTOR - (MINIMAP_HEIGHT * SCALE_FACTOR) / 2;
    int minimap_x = x * SCALE_FACTOR - cub->data->offset_x + MINIMAP_X;
    int minimap_y = y * SCALE_FACTOR - cub->data->offset_y + MINIMAP_Y;

    i = minimap_x - 1;
    while (i <= minimap_x + 2)
    {
        j = minimap_y - 1;
        while (j <= minimap_y + 2)
        {
            my_mlx_pixel_put(cub, i, j, color);
            j++;
        }
        i++;
    }
    draw_rays_minimap(cub, x, y);
}

int put_player(t_cub *cub, int x, int y, unsigned int color)
{
    int start_x;
    int start_y;
    int end_x;
    int end_y;

    start_x = x - 2;
    start_y = y - 2;
    end_x = x + 2;
    end_y = y + 2;
    if (!cub->add_minimap)
        return (0);
    if (start_x < 0)
        start_x = 0;
    if (start_y < 0)
        start_y = 0;
    if (end_x >= WIDTH)
        end_x = WIDTH - 1;
    if (end_y >= HEIGHT)
        end_y = HEIGHT - 1;
    draw_player(cub, x, y, color);
    return (1);
}

int draw_minimap(t_cub *cub, t_data *data, char **map)
{
    int final_x;
    int final_y;

    int player_x = (int)(cub->player->x * SCALE_FACTOR) / (TXT_SIZE * SCALE_FACTOR);
    int player_y = (int)(cub->player->y * SCALE_FACTOR) / (TXT_SIZE * SCALE_FACTOR);
    (void)data;
    if (!cub->add_minimap)
        return (0);
    if (player_y < 3)
        player_y = 0;
    else
        player_y -= 3;
    final_x = player_x + 6;
    final_y = player_y + 6;
    while (map[player_y] && player_y <= final_y)
    {
        player_x = (int)(cub->player->x * SCALE_FACTOR) / (TXT_SIZE * SCALE_FACTOR);
        if (player_x < 3)
            player_x = 0;
        else
            player_x -= 3;
        while (map[player_y][player_x] && player_x <= final_x)
        {
            if (map[player_y][player_x] == '1')
                draw_square(cub, player_x, player_y, BLUE);
            else if ((map[player_y][player_x] == '0' || map[player_y][player_x] == 'E' || map[player_y][player_x] == 'W'
                      || map[player_y][player_x] == 'N' || map[player_y][player_x] == 'S'))
                draw_square(cub, player_x, player_y, WHITE);
            if (map[player_y][player_x] == 'D')
                draw_square(cub, player_x, player_y, DARK_GREEN);
            if (map[player_y][player_x] == 'O')
                draw_square(cub, player_x, player_y, GREEN);
            player_x++;
        }
        player_y++;
    }
    put_player(cub, cub->player->x, cub->player->y, RED);
    return (1);
}