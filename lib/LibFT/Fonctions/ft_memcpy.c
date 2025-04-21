/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:49:50 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:00:48 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*psrc;
	char	*pdest;

	i = 0;
	psrc = (char *)src;
	pdest = (char *)dest;
	if (psrc == NULL && pdest == NULL)
		return (dest);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (pdest);
}
/*
int	main(void)
{
	const void	*src = "Bonjour";
	void	*dest;
	void	*verif;
	size_t	n = strlen(src);

	dest = malloc(sizeof(char) * (n + 1));
	verif = malloc(sizeof(char) * (n + 1));
	printf("%p\n", ft_memcpy(dest, src, n));
	printf("%p\n", memcpy(verif, src, n));
	printf("%s\n", ft_memcpy(dest, src, n));
	printf("%s\n", memcpy(verif, src, n));

	return (0);
}
*/