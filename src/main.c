/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:47:48 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:06:17 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	_fdf_check_arg(char **argv)
{
	char	*extension;

	extension = ft_strrchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".fdf", 4))
	{
		ft_putstr_fd("Error: invalid file extension\n", 1);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
	{
		ft_putstr_fd("Error: missing or too many arguments\n", 1);
		return (0);
	}
	_fdf_check_arg(av);
	fdf = malloc(sizeof(t_fdf));
	init_fdf(fdf);
	tab_init(fdf, av[1]);
	fdf->img = malloc(sizeof(t_img));
	fdf->img->img = mlx_new_image(fdf->mlx, 1200, 1200);
	if (!fdf->img->img)
	{
		ft_putstr_fd("Error: Failed to create new image\n", 1);
		return (0);
	}
	calculate_draw(fdf, fdf->proj);
	ft_display(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, ft_exit, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
