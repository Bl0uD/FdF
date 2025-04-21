/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:53:21 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:01:13 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdest;
	size_t			i;

	i = 0;
	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	if (pdest < psrc && (pdest != NULL || psrc != NULL))
	{
		while (n != 0)
		{
			pdest[i] = psrc[i];
			i++;
			n--;
		}
	}
	else if (pdest != NULL || psrc != NULL)
	{
		while (n != 0)
		{
			pdest[n - 1] = psrc[n - 1];
			n--;
		}
	}
	return (pdest);
}
/*
int	main(void)
{
	const void	*src = "Bonjour comment ca va ?";
	void		*dest;
	void		*verif;
	size_t		len = strlen(src);
	size_t		n = 2;

	dest = strdup(src);
	verif = strdup(src);
//	printf("ft_memmove = %p\n", ft_memmove(dest + 2, dest, n));
//	printf("memmove = %p\n", memmove(verif + 2, verif, n));
	printf("ft_memmove = %s\n", (char *)ft_memmove(dest + 1, dest, n));
	printf("memmove = %s\n", (char *)memmove(verif + 1, verif, n));
	return (0);
}*/