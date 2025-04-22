/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_draw_opti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:45:52 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 12:36:29 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	offset_init(t_offset *offset)
{
	offset->i = 0;
	offset->j = 0;
	offset->min_x = INT_MAX;
	offset->max_x = INT_MIN;
	offset->min_y = INT_MAX;
	offset->max_y = INT_MIN;
}

static void	calculate_offset(t_fdf *fdf,
	t_point (*func_draw)(t_fdf *, int, int), int *offset_x, int *offset_y)
{
	t_offset	of;
	t_point		point;

	offset_init(&of);
	of.i = 0;
	while (of.i < fdf->row)
	{
		of.j = 0;
		while (of.j < fdf->col)
		{
			point = func_draw(fdf, of.i, of.j);
			if (point.draw_x < of.min_x)
				of.min_x = point.draw_x;
			if (point.draw_x > of.max_x)
				of.max_x = point.draw_x;
			if (point.draw_y < of.min_y)
				of.min_y = point.draw_y;
			if (point.draw_y > of.max_y)
				of.max_y = point.draw_y;
			of.j++;
		}
		of.i++;
	}
	*offset_x = (1200 - (of.max_x - of.min_x)) / 2 - of.min_x;
	*offset_y = (1200 - (of.max_y - of.min_y)) / 2 - of.min_y;
}

void	projection_iso_opti(t_fdf *fdf)
{
	t_calculate_draw	s;
	int					offset_x;
	int					offset_y;

	s.i = -1;
	offset_x = 0;
	offset_y = 0;
	calculate_offset(fdf, projection_iso, &offset_x, &offset_y);
	while (++s.i < fdf->row)
	{
		s.j = 0;
		while (s.j < fdf->col)
		{
			s.sx = fdf->tab[s.i][s.j].origin_x * fdf->zoom;
			s.sy = fdf->tab[s.i][s.j].origin_y * fdf->zoom;
			s.sz = fdf->tab[s.i][s.j].origin_z * fdf->zoom;
			fdf->tab[s.i][s.j].draw_x = ((s.sx - s.sy) * cos(0.523599));
			fdf->tab[s.i][s.j].draw_x += offset_x + fdf->move_x;
			fdf->tab[s.i][s.j].draw_y = (-s.sz + (s.sx + s.sy) * sin(fdf->rotate));
			fdf->tab[s.i][s.j].draw_y += offset_y + fdf->move_y;
			fdf->tab[s.i][s.j].draw_z = s.sz;
			s.j++;
		}
	}
}

void	t_projectionop_opti(t_fdf *fdf)
{
	t_calculate_draw	s;
	int					offset_x;
	int					offset_y;

	s.i = -1;
	offset_x = 0;
	offset_y = 0;
	calculate_offset(fdf, t_projectionop, &offset_x, &offset_y);
	while (++s.i < fdf->row)
	{
		s.j = 0;
		while (s.j < fdf->col)
		{
			s.sx = fdf->tab[s.i][s.j].origin_x * fdf->zoom;
			s.sy = fdf->tab[s.i][s.j].origin_y * fdf->zoom;
			s.sz = fdf->tab[s.i][s.j].origin_z * fdf->zoom;
			fdf->tab[s.i][s.j].draw_x = s.sx + offset_x + fdf->move_x;
			fdf->tab[s.i][s.j].draw_y = s.sy + offset_y + fdf->move_y;
			fdf->tab[s.i][s.j].draw_z = 0;
			s.j++;
		}
	}
}

void	projection_paralelle_opti(t_fdf *fdf)
{
	t_calculate_draw	s;
	int					offset_x;
	int					offset_y;

	s.i = -1;
	offset_x = 0;
	offset_y = 0;
	calculate_offset(fdf, projection_parallel, &offset_x, &offset_y);
	while (++s.i < fdf->row)
	{
		s.j = 0;
		while (s.j < fdf->col)
		{
			s.sx = fdf->tab[s.i][s.j].origin_x * fdf->zoom;
			s.sy = fdf->tab[s.i][s.j].origin_y * fdf->zoom;
			s.sz = fdf->tab[s.i][s.j].origin_z * fdf->zoom;
			fdf->tab[s.i][s.j].draw_x = s.sx + offset_x + fdf->move_x;
			fdf->tab[s.i][s.j].draw_y = -s.sz + offset_y + fdf->move_y;
			fdf->tab[s.i][s.j].draw_z = 0;
			s.j++;
		}
	}
}
