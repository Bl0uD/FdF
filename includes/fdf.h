/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 02:28:39 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:28:39 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <limits.h>

# include "./struct_fdf.h"
# include "./libft.h"
# include "./mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		__gnl_find_newline(char *buf, int line_size);
int		__gnl_ft_get_line(char **buf, int *line_size, char **l);
int		__gnl_ft_read(char **buf, int *line_size, int fd);

char	*__gnl_free_n_return(char **buf);
char	*__gnl_ft_substr(char const *s, unsigned int start, size_t len);
char	*__gnl_get_next_line(int fd);

void	*__gnl_ft_memcpy(void *dest, const void *src, size_t n);
void	*__gnl_ft_realloc(void *ptr, size_t size, size_t new_size);

void	tab_init(t_fdf *fdf, const char *map);
void	init_fdf(t_fdf *fdf);
void	ft_strstr_free(char **split);
int		ft_atoi_base(char *str, char *base);
void	ft_display(t_fdf *fdf);

int		key_hook(int keycode, t_fdf *fdf);
int		ft_exit(t_fdf *fdf);

// PERSPECTIVE
t_point	projection_iso(t_fdf *fdf, int i, int j);
t_point	t_projectionop(t_fdf *fdf, int i, int j);
t_point	projection_parallel(t_fdf *fdf, int i, int j);
void	projection_iso_opti(t_fdf *fdf);
void	t_projectionop_opti(t_fdf *fdf);
void	projection_paralelle_opti(t_fdf *fdf);
void	calculate_draw(t_fdf *fdf, t_projection proj);
void	mlx_draw_line(t_fdf *fdf, t_point point1, t_point point2);
void	mlx_draw_line_gradient(t_fdf *fdf, t_point point1, t_point point2);
void	mlx_draw_pixel(t_fdf *fdf, int x, int y, int color);

#endif