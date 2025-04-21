/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:49:56 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:00:59 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "../Includes/libft.h"

void	*ft_memmem(const void *src, size_t srclen,
		const void *finder, size_t finderlen)
{
	size_t	i;
	size_t	j;
	char	*psrc;
	char	*pfinder;

	i = 0;
	j = 0;
	psrc = (char *)src;
	pfinder = (char *)finder;
	if (!*pfinder)
		return (psrc);
	while (i < srclen)
	{
		if (psrc[i] == pfinder[j])
			j++;
		else
			j = 0;
		if (j == finderlen)
			return (&psrc[i - j + 1]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*src = "Bonjour";
	const void	*finder = "n";
	void		*test;
	void		*verif;
	void		*a;
	void		*b;
	size_t		srclen = 7;
	size_t		finderlen = 1;

	test = strdup(src);
	verif = strdup(src);
	a = ft_memmem(test, srclen, finder, finderlen);
	b = memmem(verif, srclen, finder, finderlen);
	for (int i = 0; i < 21; i++)
		printf("%d ", ((char *)verif)[i]);
	printf("\n");
	for (int i = 0; i < 21; i++)
		printf("[%c] ", ((char *)verif)[i]);
	printf("\n");
	printf("ft_memmem = %s", a);
	printf("\n");
	printf("memmem = %s", b);
	printf("\n");
	return (0);
}*/