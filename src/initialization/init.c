/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:31:21 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 15:55:03 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1200, 1200, "FDF");
	fdf->col = 0;
	fdf->row = 0;
	fdf->tab = NULL;
	fdf->img = NULL;
	fdf->zoom = 0.8;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->proj = ISOMETRIC;
	fdf->rotate_h = 0.523599;
	fdf->rotate_v = 0.523599;
}
