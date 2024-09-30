/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:57:27 by aconti            #+#    #+#             */
/*   Updated: 2024/09/24 15:14:25 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "define.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <X11/X.h>
# include "structs.h"

//window
int		init_cube(t_cub *cub);
int		draw_minimap(t_cub *cub, t_data *data, char **map);
void	player_init(t_cub *cub);
int		put_player(t_cub *cub, int x, int y, unsigned int color);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int color);
void	draw_player(t_cub *cub, int x, int y, unsigned int color);
void	draw_rays_minimap(t_cub *cub, int x, int y);
void	adding_wall(t_cub *cub);

//parsing
int		regular_map(char *name, t_cub *cub);
int		check_zero(char **map, int x, int y, char player);
int		check_d_right(char **map, int x, int y, char player);
int		check_d_left(char **map, int x, int y, char player);
int		init_data(t_data *data);
int		check_map(char **matrix, t_data *data);
int		check_matrix(t_data *data);
int		check_map_continue(char **matrix, char player);
int		check_null_data(t_data *data);
int		get_cor(t_data *data);
void	data_max(t_data *data);
int		check_char(int c);
void	print_rays(t_player *player);
//events
void	calling_mlx(t_cub *cub);
int		close_window(t_cub *cub);
void	fill_black(t_cub *cub);
int		check_move(int keysym, t_cub *cub, char **map);
int		check_next_door(t_cub *cub);
//free
void	free_wall(t_player *player);
void	free_cub(t_cub *cub);
void	print_matrix(char **matrix);
void	free_ray(t_player *player, t_cub *cub);
//math
int		fmap(int unscaled_num, int new_max, int old_max);
//raycasting
void	start_raycast(t_cub *cub, t_player *player);
int		is_wall(long double x, long double y, t_cub *cub);
void	drawing_rays(t_player *player, t_cub *cub);
void	print_rays(t_player *player);
int     is_same(t_cub *cub, t_ray *ray, int i);
void	adding_img(t_cub *cub, int i);
void	add_wall_info(t_ray *ray, char **map, t_cub *cub);
void	draw_all(t_cub *cub, t_player *player);
void	adding_ray_info(t_ray *ray);
void	adding_pix_to_img(t_cub *cub, t_ray *ray);
void	get_w_h(t_ray *ray, t_cub *cub);
//dda
void	start_dda(t_cub *cub, t_ray *ray);

#endif