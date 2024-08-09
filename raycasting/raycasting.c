/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:09:08 by aconti            #+#    #+#             */
/*   Updated: 2024/08/09 11:31:58 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void cast_rays(t_cub *cub)
// {
//     for (int x = 0; x < WIN_WIDTH; x++) {
//         // Calcola l'angolo del raggio corrente
//         float ray_angle = (cub->player->angle - FOV / 2.0) + ((float)x / WIN_WIDTH) * FOV;
        
//         // Calcola la direzione del raggio
//         float ray_x = cos(ray_angle);
//         float ray_y = sin(ray_angle);
        
//         // Lancia il raggio finché non colpisce un muro
//         float distance = 0;
//         int hit_wall = 0;
//         while (!hit_wall && distance < MAX_RENDER_DISTANCE) {
//             distance += 0.1;  // Incrementa la distanza percorsa dal raggio
            
//             int map_x = (int)(cub->player->x + ray_x * distance);
//             int map_y = (int)(cub->player->y + ray_y * distance);
            
//             // Controlla se il raggio ha colpito un muro
//             if (cub->data->map[map_y][map_x] > 0) {
//                 hit_wall = 1;
//             }
//         }

//         // Calcola l'altezza della parete
//         int wall_height = (int)(WIN_HEIGHT / (distance * cos(ray_angle - cub->player->angle)));
        
//         // Disegna la parete sullo schermo
//         draw_wall(x, wall_height, cub);
//     }
// }