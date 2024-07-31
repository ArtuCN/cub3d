/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:57:27 by aconti            #+#    #+#             */
/*   Updated: 2024/07/31 17:49:11 by aconti           ###   ########.fr       */
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
	t_img		*img;
	char		**map;
}				t_cub;



//window
int	init_cube(t_cub *cub);
//parsing
int	regular_map(char *name, t_cub *cub);
int	check_map(t_cub *cub);
//events
void	events(t_cub *cub);


#endif