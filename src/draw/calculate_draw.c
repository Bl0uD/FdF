/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:17 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:33:55 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	calculate_draw(t_fdf *fdf, t_projection proj)
{
	if (proj == ISOMETRIC)
		projection_iso_opti(fdf);
	else if (proj == TOP)
		t_projectionop_opti(fdf);
	else if (proj == PARALLEL)
		projection_paralelle_opti(fdf);
}
