/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:57:27 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 17:33:47 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "define.h"
# include "structs.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <X11/X.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>

//sword
void			drawing_sword(t_cub *cub);
unsigned int	get_sprite_pixel_color(t_sword *sword, int x, int y);
//mouse
int				main_loop(t_cub *cub);
void			rotate_pov(t_cub *cub, int x, int y);
//window
int				init_cube(t_cub *cub);
int				draw_minimap(t_cub *cub, t_data *data, char **map);
void			player_init(t_cub *cub);
int				put_player(t_cub *cub, int x, int y, unsigned int color);
void			my_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int color);
void			draw_player(t_cub *cub, int x, int y, unsigned int color);
void			draw_rays_minimap(t_cub *cub, int x, int y);
void			adding_wall(t_cub *cub);
int				is_wall(long double x, long double y, t_cub *cub);
int				is_wall_minimap(long double x, long double y, t_cub *cub);
int				put_player(t_cub *cub, int x, int y, unsigned int color);
//parsing
int				regular_map(char *name, t_cub *cub);
int				check_zero(char **map, int x, int y, char player);
int				check_d_right(char **map, int x, int y, char player);
int				check_d_left(char **map, int x, int y, char player);
int				init_data(t_data *data);
int				check_map(char **matrix, t_data *data);
int				check_matrix(t_data *data);
int				check_map_continue(char **matrix, char player);
int				check_null_data(t_data *data);
int				get_cor(t_data *data);
int				data_max(t_data *data);
int				check_char(int c);
//events
void			free_matrix(char **mat);
void			calling_mlx(t_cub *cub);
int				close_window(t_cub *cub);
void			fill_black(t_cub *cub);
int				check_move(int keysym, t_cub *cub, char **map);
int				check_next_door(t_cub *cub);
void			rotate_pov(t_cub *cub, int x, int y);
int				key_handler(int keysym, t_cub *cub);
void			adding_minimap(int keysym, t_cub *cub);
int				key_handler_pause(int keysym, t_cub *cub);
int				go_f(t_cub *cub, long double *x,
					long double *y, long double angle);
int				go_b(t_cub *cub, long double *x,
					long double *y, long double angle);

//press_release
int				key_press(int keysym, t_cub *cub);
int				key_release(int keysym, t_cub *cub);
void			press1(int keysym, t_cub *cub);
void			press2(int keysym, t_cub *cub);
//free
void			free_wall(t_player *player);
void			free_cub(t_cub *cub);
void			free_data(t_cub *cub);
//math
int				fmap(int unscaled_num, int new_max, int old_max);
//raycasting
int				is_wall(long double x, long double y, t_cub *cub);
void			print_rays(t_player *player);
int				is_same(t_cub *cub, t_ray *ray, int i);
void			adding_img(t_cub *cub, int i);
void			add_wall_info(t_ray *ray, char **map, t_cub *cub);
void			draw_all(t_cub *cub, t_player *player);
void			adding_ray_info(t_ray *ray);
void			adding_pix_to_img(t_cub *cub, t_ray *ray);
void			get_w_h(t_ray *ray, t_cub *cub);
void			get_sprites0_4(t_cub *cub, int i);
void			get_sprites5_8(t_cub *cub, int i);
void			get_sprites9_12(t_cub *cub, int i);
void			get_texture(t_cub *cub, int i);
//dda
void			start_dda(t_cub *cub, t_ray *ray);
void			wall_draw_info(t_cub *cub, t_ray *ray);
void			draw_pause(t_cub *cub);
void			some_other_init(t_dda *dda, t_player *player,
					long double temp_ang);
void			init_ray(t_ray *ray, t_dda *dda, t_cub *cub, int i);
void			dist(t_dda *dda, t_cub *cub, t_ray *ray, int i);
void			add_direction(t_ray *ray, t_dda *dda);
void			draw_cealing(int *i, t_ray *ray, int temp, t_cub *cub);
void			draw_floor(int *i, t_ray *ray, int temp, t_cub *cub);

#endif