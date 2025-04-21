/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:01:14 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:57:17 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strnstr(const char *str, const char *finder, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if ((!str || !finder) && len == 0)
		return (NULL);
	if (ft_strlen(finder) == 0)
		return ((char *)str);
	if ((int)len < 0)
		return (ft_strnstr(str, finder, ft_strlen(str)));
	if (len == 1 && str[0] == finder[0])
		return ((char *)str);
	while ((char)str[i] && i < (int)len - 1)
	{
		j = 0;
		while ((char)str[i + j] == (char)finder[j])
		{
			if (j == (int)ft_strlen((char *)finder) - 1 && i + j < (int)len)
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	char	*str = av[1]; //"Bonjour les amis";
	char	*finder = av[2]; //"les";
	size_t	len = strlen(str);

	printf("ft_strnstr = %s\n", ft_strnstr(str, finder, len));
	printf("strnstr = %s\n", strnstr(str, finder, len));
	return (0);
}
*/