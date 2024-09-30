// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   raycasting.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/09 11:09:08 by aconti            #+#    #+#             */
// /*   Updated: 2024/09/25 13:04:22 by aconti           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cub3d.h"

// void	ray_distance(t_player *player, int i, long double temp_ang)
// {
// 	double	step_x;
// 	double	step_y;
	
// 	player->ray[i].from_x = player->ray[i].x;
// 	player->ray[i].from_y = player->ray[i].y;
// 	if (temp_ang > 360)
// 		temp_ang -= 360;
// 	else if (temp_ang <= 0)
// 		temp_ang += 360;
// 	step_x = 0.5 * cos(temp_ang * PI / 180L);
// 	step_y = 0.5 * sin(temp_ang * PI / 180L);
// 	player->ray[i].x += step_x;
// 	player->ray[i].y += step_y;
// 	player->ray[i].distance += sqrt(step_x * step_x + step_y * step_y) * 0.15;
// 	player->ray[i].distance = fabs((double)player->ray[i].distance);
// }

// // void	function(t_wall *wall, t_cub *cub, t_ray *ray)
// // {
// // 	ray->hit_x
// // }


// void	change_ray_info(t_ray *ray)
// {
// 	long double temp_distance;
// 	long double rd;
// 	long double wd;
	
// 	rd = ray->distance;
// 	wd = ray->wall->distance;
// 	temp_distance = sqrt((rd * rd) + (wd * wd) - (2 * rd * wd) * cos((ray->angle) * (PI / 180.0)));
	
// 	temp_distance = temp_distance - (long double)floor(temp_distance);
// 	ray->hit_y = ray->wall->first_hit_y - temp_distance;
// 	ray->hit_x = ray->wall->first_hit_x + temp_distance;
// 	if (ray->wall->direction == 'N')
// 		ray->hit_x = ray->hit_x + (long double)floor(ray->hit_x);
// 	else if (ray->wall->direction == 'S')
// 		ray->hit_x = ray->hit_x - (long double)floor(ray->hit_x);
// 	else if (ray->wall->direction == 'W')
// 		ray->hit_y = ray->hit_y - (long double)floor(ray->hit_y);
// 	else if (ray->wall->direction == 'E')
// 		ray->hit_y = ray->hit_y + (long double)floor(ray->hit_y);
// }	

// void	start_raycast(t_cub *cub, t_player *player)
// {
// 	t_ray		*ray;
// 	int			i;
// 	long double	temp_ang;
// 	i = -1;

// 	temp_ang = (long double)(cub->player->angle - 30);
// 	ray = player->ray;
// 	while (++i < player->num_rays)
// 	{
// 		ray[i].x = cub->player->x;
// 		ray[i].y = cub->player->y;
// 		ray[i].distance = 0;
// 		while (!is_wall(ray[i].x, ray[i].y, cub))
// 			ray_distance(player, i, temp_ang);
// 		ray[i].angle = temp_ang;
// 		ray[i].distance *= cos((temp_ang - cub->player->angle) * PI / 180);
// 		adding_ray_info(&ray[i]);
// 		ray[i].angle = temp_ang;
// 		if (!is_same(ray, i))
// 		{
// 			ray[i].wall = malloc(sizeof(t_wall));
// 			ray[i].wall->n_rays = 0;
// 			add_wall_info(&ray[i], cub->data->map, cub);
// 			cub->num_walls++;
// 		}
// 		else
// 		{
// 			ray[i].wall = ray[i - 1].wall;
// 			change_ray_info(&ray[i]);
// 		}
// 		temp_ang += player->increment;
// 	}
// 	adding_pix_to_img(cub, ray);
// }
