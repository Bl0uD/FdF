/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:36:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:57:19 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[i] && i <= n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
