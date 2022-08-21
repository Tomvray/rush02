/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:02 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 16:24:46 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void	ft_putstr(char *str);
void	ft_putchar(char c);

void	ft_put_digit(char *nbr, int size, char ***dict)
{
	int	k;
	int	res;

	k = 0;
	res = 1;
	while (k < 41)
	{
		if (res && size_int(dict[k][0]) == size)
		{
			if (ft_strncmp(dict[k][0], nbr, size) == 0)
			{
				ft_putstr(dict[k][1]);
				res = 0;
			}
		}
		k++;
	}
	ft_putchar(' ');
}

void	ft_print_ten(char *nbr, int size, char ***dict)
{
	char	tab[2];

	tab[0] = nbr[0];
	if (size == 2)
		tab[1] = nbr[1];
	else
		tab[1] = '0';
	ft_put_digit(tab, 2, dict);
}

void	ft_print_hundred(char *nbr, int size, char ***dict)
{
	int	i;

	i = 0;
	if (size == 3)
	{
		if (nbr[i] != '0')
		{
			ft_put_digit(nbr + i, 1, dict);
			ft_put_digit("100", 3, dict);
		}
		i++;
		size--;
	}
	if (size == 2)
	{
		if (nbr [i] != '0')
		{
			if (nbr[i] == '1')
			{
				ft_print_ten(nbr + i, 2, dict);
				size --;
			}
			else
			{
				ft_print_ten(nbr + i, 1, dict);
			}
		}
		size --;
		i++;
	}
	if (size == 1 && nbr[i] != '0')
		ft_put_digit(nbr + i, 1, dict);
}

void	ft_put_thousand(int size, char ***dict)
{
	int	k;
	int	res;
	int	i;

	i = 1;
	k = 0;
	res = 1;
	while (k < 41)
	{
		if (res && size_int(dict[k][0]) == size)
		{
			if (dict[k][0][0] == '1')
			{
				while (dict[k][0][i] == '0')
					i++;
			}
			if (i == size)
			{
				ft_putstr(dict[k][1]);
				res = 0;
			}
		}
		k++;
	}
	ft_putchar(' ');
}
