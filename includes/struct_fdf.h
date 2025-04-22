/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fdf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 02:28:08 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:28:08 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FDF_H
# define STRUCT_FDF_H

typedef enum projection_e
{
	ISOMETRIC,
	PARALLEL,
	TOP,
}			t_projection;

typedef struct s_point
{
	int		origin_x;
	int		origin_y;
	int		origin_z;
	int		draw_x;
	int		draw_y;
	int		draw_z;
	int		color;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	int				move_x;
	int				move_y;
	t_projection	proj;
	void			*mlx;
	void			*win;
	t_point			**tab;
	float			zoom;
	float			rotate_h;
	float			rotate_v;
	int				row;
	int				col;
	t_img			*img;
}				t_fdf;

typedef struct s_line
{
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	error;
	int	error2;
}				t_line;

typedef struct s_offset
{
	int	i;
	int	j;
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
}				t_offset;

typedef struct s_calculate_draw
{
	int		*offset_x;
	int		*offset_y;
	int		i;
	int		j;
	float	sx;
	float	sy;
	float	sz;
}				t_calculate_draw;

#endif