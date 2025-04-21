/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:57:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:01:16 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	void	*src = "Bonjour";
	void	*dest;
	void	*test;
	int		c = 'A';
	size_t	n = 10;

	dest = strdup(src);
	ft_memset(dest, c, n);
//	memcpy(dest + 5, src, n);
	for (int i = 0; i < 21; i++)
		printf("%d ", ((char *)dest)[i]);
	printf("\n");
//	for (int i = 0; i < 21; i++)
//		printf("%d ", ((char *)dest)[i]);
//	printf("\n");
	for (int i = 0; i < 21; i++)
		printf("[%c] ", ((char *)dest)[i]);
	printf("\n");
//	for (int i = 0; i < 21; i++)
//		printf("[%c] ", ((char *)dest)[i]);
//	printf("\n");
	return (0);
}*/