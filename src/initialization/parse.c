/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:52:14 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/22 02:35:39 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	parse(t_fdf *fdf, const char *map)
{
	int		fd;
	char	*line;
	char	*old_line;
	char	**split;

	fd = open(map, O_RDONLY);
	line = __gnl_get_next_line(fd);
	while (line)
	{
		old_line = ft_strdup(line);
		free(line);
		line = __gnl_get_next_line(fd);
		if (line == NULL)
		{
			split = ft_split(old_line, ' ');
			while (split[fdf->col] != NULL)
				fdf->col++;
			ft_strstr_free(split);
		}
		free(old_line);
		fdf->row++;
	}
}

static void	populate_child(t_fdf *fdf, char *line, int i)
{
	char	**split;
	char	**t;
	int		j;

	split = ft_split(line, ' ');
	j = 0;
	while (split[j])
	{
		t = ft_split(split[j], ',');
		fdf->tab[i][j].origin_x = j * 20;
		fdf->tab[i][j].origin_y = i * 20;
		fdf->tab[i][j].origin_z = ft_atoi(t[0]);
		fdf->tab[i][j].draw_x = 0;
		fdf->tab[i][j].draw_y = 0;
		fdf->tab[i][j].draw_z = 0;
		if (t[1])
			fdf->tab[i][j].color = ft_atoi_base(t[1] + 2, "0123456789ABCDEF");
		else
			fdf->tab[i][j].color = 0xFFFFFF;
		j++;
		ft_strstr_free(t);
	}
	ft_strstr_free(split);
}

static void	populate(t_fdf *fdf, const char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = __gnl_get_next_line(fd);
	while (line)
	{
		populate_child(fdf, line, i);
		free(line);
		i++;
		line = __gnl_get_next_line(fd);
	}
}

void	tab_init(t_fdf *fdf, const char *map)
{
	int	i;

	parse(fdf, map);
	i = -1;
	if (fdf->row == 0 || fdf->col == 0)
		return ;
	fdf->tab = (t_point **)malloc(sizeof(t_point *) * fdf->row);
	if (!fdf->tab)
		return ;
	while (++i < fdf->row)
		fdf->tab[i] = (t_point *)malloc(sizeof(t_point) * fdf->col);
	populate(fdf, map);
}
