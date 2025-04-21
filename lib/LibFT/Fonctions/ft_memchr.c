/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:49:21 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:00:43 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sp;
	unsigned char	cp;

	i = 0;
	sp = (unsigned char *)s;
	cp = (unsigned char)c;
	while (i < n)
	{
		if (sp[i] == cp)
			return (&sp[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*src = "Bonjour comment ca va ?";
	void		*dest;
	char		*verif;
	int			c = 'c';
	size_t		n = strlen(src);

	dest = strdup(src);
	verif = strdup(src);
	printf("ft_memchr = %p\n", ft_memchr(src, c, n));
	printf("memchr = %p\n", memchr(src, c, n));
	printf("ft_memchr = %s\n", (char *)ft_memchr(src, c, n));
	printf("memchr = %s\n", (char *)memchr(src, c, n));
	return (0);
}
*/