/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:09:30 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 15:09:34 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_put_space(char *nbr, int print)
{
	int	i;

	i = 0;
	while (nbr[i] && nbr[i] == '0')
		i++;
	if ((nbr[i] <= '9' && nbr[i] > '0'))
	{
		if (print)
			ft_putchar(' ');
		return (1);
	}
	return (0);
}
