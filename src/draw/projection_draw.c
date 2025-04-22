/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:08 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:34:12 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_point	projection_iso(t_fdf *fdf, int i, int j)
{
	t_point	point;
	float	scaled_x;
	float	scaled_y;
	float	scaled_z;

	scaled_x = fdf->tab[i][j].origin_x * fdf->zoom;
	scaled_y = fdf->tab[i][j].origin_y * fdf->zoom;
	scaled_z = fdf->tab[i][j].origin_z * fdf->zoom;
	point.draw_x = (scaled_x - scaled_y) * cos(0.523599);
	point.draw_y = -scaled_z + (scaled_x + scaled_y) * sin(0.523599);
	point.draw_z = scaled_z;
	point.color = fdf->tab[i][j].color;
	return (point);
}

t_point	t_projectionop(t_fdf *fdf, int i, int j)
{
	t_point	point;
	float	scaled_x;
	float	scaled_y;

	scaled_x = fdf->tab[i][j].origin_x * fdf->zoom;
	scaled_y = fdf->tab[i][j].origin_y * fdf->zoom;
	point.draw_x = scaled_x;
	point.draw_y = scaled_y;
	point.draw_z = 0;
	point.color = fdf->tab[i][j].color;
	return (point);
}

t_point	projection_parallel(t_fdf *fdf, int i, int j)
{
	t_point	point;
	float	scaled_x;
	float	scaled_z;

	scaled_x = fdf->tab[i][j].origin_x * fdf->zoom;
	scaled_z = fdf->tab[i][j].origin_z * fdf->zoom;
	point.draw_x = scaled_x;
	point.draw_y = -scaled_z;
	point.draw_z = 0;
	point.color = fdf->tab[i][j].color;
	return (point);
}
