/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:13:02 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/21 19:13:02 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1200 || y < 0 || y >= 1200)
		return ;
	dst = fdf->img->addr + (y * fdf->img->line_length + x
			* (fdf->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_gradient_color(t_point point1,
				t_point point2, t_point current)
{
	float	percentage;
	int		red;
	int		green;
	int		blue;

	if (point1.draw_x == point2.draw_x)
		percentage = (float)(current.draw_y - point1.draw_y)
			/ (point2.draw_y - point1.draw_y);
	else
		percentage = (float)(current.draw_x - point1.draw_x)
			/ (point2.draw_x - point1.draw_x);
	red = (int)((1 - percentage) * ((point1.color >> 16)
				& 0xFF) + percentage * ((point2.color >> 16) & 0xFF));
	green = (int)((1 - percentage) * ((point1.color >> 8)
				& 0xFF) + percentage * ((point2.color >> 8) & 0xFF));
	blue = (int)((1 - percentage) * (point1.color & 0xFF)
			+ percentage * (point2.color & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

static void	fill_line_struct(t_line *line, t_point point1, t_point point2)
{
	line->delta_x = abs(point2.draw_x - point1.draw_x);
	line->delta_y = abs(point2.draw_y - point1.draw_y);
	if (point1.draw_x < point2.draw_x)
		line->sign_x = 1;
	else
		line->sign_x = -1;
	if (point1.draw_y < point2.draw_y)
		line->sign_y = 1;
	else
		line->sign_y = -1;
	line->error = line->delta_x - line->delta_y;
}

void	mlx_draw_line_gradient(t_fdf *fdf, t_point point1, t_point point2)
{
	t_line	line;
	t_point	current;

	fill_line_struct(&line, point1, point2);
	current = point1;
	while (current.draw_x != point2.draw_x || current.draw_y != point2.draw_y)
	{
		mlx_draw_pixel(fdf, current.draw_x, current.draw_y,
			get_gradient_color(point1, point2, current));
		line.error2 = line.error * 2;
		if (line.error2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			current.draw_x += line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			current.draw_y += line.sign_y;
		}
	}
	mlx_draw_pixel(fdf, current.draw_x, current.draw_y, point2.color);
}

void	mlx_draw_line(t_fdf *fdf, t_point point1, t_point point2)
{
	t_line	line;

	fill_line_struct(&line, point1, point2);
	while (point1.draw_x != point2.draw_x || point1.draw_y != point2.draw_y)
	{
		mlx_draw_pixel(fdf, point1.draw_x, point1.draw_y, point1.color);
		line.error2 = line.error * 2;
		if (line.error2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			point1.draw_x += line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			point1.draw_y += line.sign_y;
		}
	}
}
