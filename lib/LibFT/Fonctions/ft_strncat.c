/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:00:18 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:58:20 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strncat(char *dest, const char *str, size_t n)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	if (n == 0)
		return (0);
	dest_len = ft_strlen(dest);
	while (str[i] && i < n)
	{
		dest[dest_len + i] = str[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
