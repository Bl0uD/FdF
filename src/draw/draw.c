/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:46 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:34:04 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_mlx_draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1200 || y < 0 || y >= 1200)
		return ;
	dst = fdf->img->addr + (y * fdf->img->line_length + x
			* (fdf->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_points(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->col)
		{
			ft_mlx_draw_pixel(fdf, fdf->tab[i][j].draw_x,
				fdf->tab[i][j].draw_y, fdf->tab[i][j].color);
			j++;
		}
		i++;
	}
}

static void	draw_row(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->col)
		{
			if (j + 1 < fdf->col)
				mlx_draw_line_gradient(fdf,
					fdf->tab[i][j], fdf->tab[i][j + 1]);
			if (i + 1 < fdf->row)
				mlx_draw_line_gradient(fdf,
					fdf->tab[i][j], fdf->tab[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	ft_display(t_fdf *fdf)
{
	if (fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	else
	{
		fdf->img->img = mlx_new_image(fdf->mlx, 1200, 1200);
		if (!fdf->img->img)
		{
			ft_putstr_fd("Error: Failed to create new image\n", 1);
			return ;
		}
	}
	fdf->img->img = mlx_new_image(fdf->mlx, 1200, 1200);
	if (!fdf->img->img)
	{
		ft_putstr_fd("Error: Failed to create new image\n", 1);
		return ;
	}
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	draw_points(fdf);
	draw_row(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}
