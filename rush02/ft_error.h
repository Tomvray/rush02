/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:36:34 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 16:05:15 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <unistd.h>

char	***ft_openfailed(void)
{
	write (1, "OPEN() Failed\n", 14);
	return (NULL);
}

int	ft_printerror(void)
{
	write (1, "Dict Error\n", 11);
	return (0);
}

char	***ft_error(void)
{
	write (1, "ERROR\n", 6);
	return (NULL);
}
int	ft_ctrldict_error(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if ((str[i] < 48 || str[i] > 57) && str[i] != 10)
			return (ft_printerror());
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] != ':' && str[i] != 10)
			return (ft_printerror());
		i++;
		while (str[i] == ' ')
			i++;
		while (str[i] != '\n')
		{
			if (str[i] < 32 || str[i] == 127)
				return (ft_printerror());
			i++;
		}
		i++;
	}
	return (1);
}
#endif
