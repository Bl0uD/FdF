/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:07 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 16:00:11 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include <limits.h>

char	*ft_alloc(int *i, int signe, long n)
{
	char	*a;

	if (n == 0)
		(*i)++;
	while (n > 0)
	{
		n /= 10;
		(*i)++;
	}
	a = ft_memalloc((*i) + signe + 1);
	if (!a)
		return (NULL);
	if (signe == 1)
	{
		a[0] = '-';
		(*i)++;
	}
	a[(*i)] = '\0';
	return (a);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		j;
	int		signe;
	long	temp;

	i = 0;
	signe = 0;
	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		signe = 1;
	}
	res = ft_alloc(&i, signe, temp);
	if (!res)
		return (NULL);
	j = 1;
	while (i > j - 1 + signe)
	{
		res[i - j] = (temp % 10) + '0';
		temp /= 10;
		j++;
	}
	return (res);
}
/*
int	main(void)
{
	int		n = -2147483648;
	char	*res = ft_itoa(n);

	printf("resultat = %s\n", res);
}
*/