/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:15:22 by artucn            #+#    #+#             */
/*   Updated: 2024/10/03 17:11:22 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data	t_data;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_wall
{
	int		n_rays;
	int		id;
	long double first_hit_x;
	long double first_hit_y;
	long double	distance;
	int		height;
	int		width;
	char	direction;
	int		door;
	int		x;
	int		y;
	int		first_pix_on_screen;
	int		widht_pix_on_screen;
	int		last_pix_on_screen;
	double	wall_start;
	double	wall_end;
}		t_wall;

typedef struct s_wall_cub
{
	int		height;
	int		width;
	t_img	*img;
}		t_wall_cub;

typedef struct s_ray
{
	long double			x;
	long double			y;
	long double			hit_x;
	long double			hit_y;
	int				start_width;
	int				end_width;
	double			angle;
	long double		distance;
	double			from_x;
	double			from_y;
	double			wall_start;
	double			wall_end;
	double			wall_height;
	unsigned int	color;
	t_img			*column_img;
	t_wall			*wall;
}				t_ray;

typedef struct s_dda
{
	long double angle;
	double		posX;
	double		posY;
	int		side;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
}	t_dda;


typedef struct s_player
{
	long double	increment;
	double		x;
	double		y;
	double		angle;
	t_ray		*ray;
	int			num_rays;
}				t_player;

typedef struct s_sword
{
	int		width;
	int		height;
	t_img	*img;
}				t_sword;


typedef struct s_cub
{
	int			x_mouse;
	int			y_mouse;	
	int			show_sword;
	char		*name;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			len;
	int			add_minimap;
	t_img		*img;
	t_data		*data;
	t_player	*player;
	t_wall_cub	*wall_cub;
	t_sword		*sword;
	t_dda		*dda;
	int			pressed;
	int			num_walls;
}				t_cub;

typedef struct s_data
{
	unsigned int	color_floor;
	unsigned int	color_ceiling;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	char			**matrix;
	char			**map;
	int				offset_x;
	int				offset_y;
	int				max_x;
	int				max_y;
	t_img			*img_map;
	char			player_dir;
}				t_data;

#endif