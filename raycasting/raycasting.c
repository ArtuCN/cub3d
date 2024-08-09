/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:09:08 by aconti            #+#    #+#             */
/*   Updated: 2024/08/09 14:54:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int is_wall(int x, int y, t_cub *cub)
{
    int map_x = fmap(x, cub->data->max_x, WIDTH);
    int map_y = fmap(y, cub->data->max_y, HEIGHT);

    // Debugging: Stampa le coordinate della mappa
    printf("Checking wall at map coordinates (%d, %d)\n", map_x, map_y);

    if (cub->data->map[map_y][map_x] == '1')
	{
		printf("FOUND WALL at (%d, %d)\n", map_y, map_x);
		return (1);
	}
	return (0);
}

void find_wall(t_cub *cub)
{
	int x = cub->player->x;
	int y = cub->player->y;
	int i = 0;

	while (!is_wall(x, y, cub) && i < 2000)
	{
		// Disegna la linea
		my_mlx_pixel_put(cub, x, y, GREEN);

		// Aggiorna x e y con un piccolo passo
		x += 2 * cos(cub->player->angle * PI / 180);
		y += 2 * sin(cub->player->angle * PI / 180);

		// Debugging: Stampa le coordinate attuali
		printf("Drawing at coordinates (%d, %d)\n", x, y);

		i++;
	}
	
}


// void draw_wall(int x, int height, t_cub *cub) {
//     int start = (HEIGHT / 2) - (height / 2);
//     int end = start + height;

//     // Disegna i pixel della colonna
//     int y = start;
//     while (y < end) {
//         my_mlx_pixel_put(cub, x, y, RED);
//         y++;
//     }
// }

// void cast_rays(t_cub *cub)
// {
//     for (int x = 0; x < WIDTH; x++) {
//         // Calcola l'angolo del raggio corrente
//         float ray_angle = (cub->player->angle - FOV / 2.0) + ((float)x / WIDTH) * FOV;
        
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
//             if (cub->data->map[map_y][map_x] == 1) {
//                 hit_wall = 1;
//             }
//         }

//         // Calcola l'altezza della parete
//         int wall_height = (int)(HEIGHT / (distance * cos(ray_angle - cub->player->angle)));
        
//         // Disegna la parete sullo schermo
//         draw_wall(x, wall_height, cub);
//     }
// }