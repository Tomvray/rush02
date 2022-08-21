/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:27:18 by tvray             #+#    #+#             */
/*   Updated: 2022/08/21 17:27:20 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((size + 1) * sizeof(char));
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (i < n - 1 && s1[i] != 0 && s2[i] != 0)
		{
			if (s1[i] != s2[i])
			{
				return (s1[i] - s2[i]);
			}
			i++;
		}
		return (s1[i] - s2[i]);
	}
	else
		return (0);
}

int	size_int(char	*str)
{
	int	i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		i++;
	}
	return (i);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != 10)
	{
		i++;
	}
	return (i);
}
