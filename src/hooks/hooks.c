/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:24:21 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:34:23 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_exit(t_fdf *fdf)
{
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img && fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	if (fdf->tab)
	{
		while (fdf->row)
			free(fdf->tab[--fdf->row]);
		free(fdf->tab);
	}
	if (fdf->img)
		free(fdf->img);
	if (fdf->mlx)
		free(fdf->mlx);
	free(fdf);
	exit(0);
}

void	keyboard_movement(t_fdf *fdf, int keycode)
{
	if (keycode == 122)
	{
		fdf->move_y += 10;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	if (keycode == 115)
	{
		fdf->move_y -= 10;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	if (keycode == 113)
	{
		fdf->move_x += 10;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	if (keycode == 100)
	{
		fdf->move_x -= 10;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
}

void	keyboard_projection(t_fdf *fdf, int keycode)
{
	if (keycode == 116)
	{
		fdf->proj = TOP;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	if (keycode == 112)
	{
		fdf->proj = PARALLEL;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	if (keycode == 105)
	{
		fdf->proj = ISOMETRIC;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
}

int	key_hook(int keycode, t_fdf *fdf)
{
	keyboard_movement(fdf, keycode);
	keyboard_projection(fdf, keycode);
	if (keycode == 65307)
	{
		ft_exit(fdf);
		return (0);
	}
	if (keycode == 65362)
	{
		if (fdf->zoom < 4)
			fdf->zoom *= 1.1;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	else if (keycode == 65364)
	{
		if (fdf->zoom > 0.1)
			fdf->zoom *= 0.9;
		calculate_draw(fdf, fdf->proj);
		ft_display(fdf);
	}
	return (0);
}
