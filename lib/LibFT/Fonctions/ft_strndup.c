/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:01:09 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:58:09 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	ft_strncpy(res, s, n);
	return (res);
}
/*
int	main(void)
{
	const char	*str = "Bonjour";
	size_t	n = 5;

	printf("ft_strndup = %s\n", ft_strndup(str, n));
	printf("strndup = %s\n", strndup(str, n));
	return (0);
}*/