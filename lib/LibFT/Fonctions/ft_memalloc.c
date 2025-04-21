/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:34:06 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:00:32 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	res = (unsigned char *)malloc(size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
/*
int	main(void)
{
	void	*res;
	size_t	size = 0;

	res = ft_memalloc(size);
	for (int i = 0; i < size; i++)
		printf("%d ", ((char *)res)[i]);
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("[%c] ", ((char *)res)[i]);
	printf("\n");
	printf("ft_memalloc = %s", res);
	printf("\n");
	return (0);
}*/