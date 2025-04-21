/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:02:33 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:57:47 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "../Includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	last_c = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_c = (char *)s;
		s++;
	}
	return (last_c);
}
/*
int	main(void)
{
	const char	*str = "Bonjour les amis";
	int			c = '\0';

	printf("ft_strrchr = %p\n", ft_strrchr(str, c));
	printf("strrchr = %p\n", strrchr(str, c));
	return (0);
}
*/