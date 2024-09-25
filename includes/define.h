/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:10:54 by aconti            #+#    #+#             */
/*   Updated: 2024/09/25 14:41:09 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define EPSILON 0.0001
# define WALL 1
# define EMPTY 0
# define WIDTH 1500
# define HEIGHT 1000
#define MINIMAP_SCALE 0.25
#define MINIMAP_WIDTH (WIDTH * MINIMAP_SCALE)
#define MINIMAP_HEIGHT (HEIGHT * MINIMAP_SCALE)
#define MINIMAP_X (0)
#define MINIMAP_Y (0)
# define FOV 60
# define MAX_RENDER_DISTANCE 2.0

# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define VIOLET 0xFF00FF
# define DARK_GREEN 0x274E13

# define PI 3.14159265358979323846
# define SYM_A 97
# define SYM_D 100
# define SYM_S 115
# define SYM_W 119
# define SYM_M 109
# define SYM_E 101

# define DOOR 0
# define WALL_N 1
# define WALL_S 2
# define WALL_W 3
# define WALL_E 4
#endif
