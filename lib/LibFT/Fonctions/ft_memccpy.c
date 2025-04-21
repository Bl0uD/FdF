/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:49:12 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:00:28 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*psrc;

	i = 0;
	psrc = (char *)src;
	while (i < n && psrc[i] != c)
	{
		((char *)dest)[i] = psrc[i];
		i++;
	}
	if (i == n)
		return (NULL);
	return (dest + i + 1);
}
/*
int	main(void)
{
	const void	*src = "Bonjour comment ca va ?";
	void		*dest;
	char		*verif;
	int			c = 'B';
	size_t		n = strlen(src);

	dest = strdup(src);
	verif = strdup(src);
	printf("ft_memccpy = %p\n", ft_memccpy(dest, src, c, n));
	printf("memccpy = %p\n", memccpy(verif, src, c, n));
	printf("ft_memccpy = %s\n", (char *)ft_memccpy(dest, src, c, n));
	printf("memccpy = %s\n", (char *)memccpy(verif, src, c, n));
	return (0);
}
*/