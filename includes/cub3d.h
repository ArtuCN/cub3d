/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:57:27 by aconti            #+#    #+#             */
/*   Updated: 2024/08/02 17:44:09 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "define.h"
# include <stdio.h>
# include <X11/X.h>


typedef struct s_data t_data;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_cub
{
	char 		*name;
	void		*mlx;
	void		*win;
	int 		width;
	int 		height;
	int			len;
	t_img		*img;
	t_data		*data;
}				t_cub;

typedef struct s_data
{
	char *north;
	char *south;
	char *west;
	char *east;
	char *floor;
	char *ceiling;
	char **matrix;
	char **map;
	int		max_x;
	int		max_y;
	char player_dir;
}				t_data;


//window
int	init_cube(t_cub *cub);
int	draw_minimap(t_cub *cub, char **map);

//parsing
int	regular_map(char *name, t_cub *cub);
int	check_zero(char **map, int x, int y, char player);
int check_d_right(char **map, int x, int y, char player);
int check_d_left(char **map, int x, int y, char player);

int	init_data(t_data *data);
int check_map(char **matrix, t_data *data);
int	check_matrix(t_data *data);
int	check_map_continue(char **matrix, char player);
//events
void	events(t_cub *cub);
//free
void	free_cub(t_cub *cub);
void	print_matrix(char **matrix);
//math
int	fmap(int unscaled_num, int new_max, int old_max);


#endif