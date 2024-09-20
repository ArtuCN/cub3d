/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:15:22 by artucn            #+#    #+#             */
/*   Updated: 2024/09/20 15:18:50 by aconti           ###   ########.fr       */
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
	int		height;
	int		width;
	char	direction;
	int		door;
	int		x;
	int		y;
	long double	wall_hit_x;
	long double	wall_hit_y;
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
	double			x;
	double			y;
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
	unsigned int	color;
	t_img			*column_img;
	t_wall			*wall;
}				t_ray;



typedef struct s_player
{
	long double	increment;
	double		x;
	double		y;
	double		angle;
	t_ray		*ray;
	int			num_rays;
}				t_player;

typedef struct s_cub
{
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