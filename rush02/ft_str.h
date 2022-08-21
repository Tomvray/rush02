/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:42:07 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 16:22:15 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STR_H
# define FT_STR_H
# include <stdlib.h>

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

#endif
