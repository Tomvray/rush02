/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:12:07 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 17:44:56 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr.h"
#include "ft_str.h"
#include "functions_print.h"
#include <stdlib.h>

char	***dict_gen(char *dico_name);
void	ft_free(char ***dict);

char	*ft_clean_number(char	*nbr)
{
	int	i;
	int	size;

	i = 0;
	while (nbr[0] == ' ' || (9 <= nbr[0] && nbr[0] <= 13))
		nbr = nbr + 1;
	if (nbr[i] == '+')
		nbr = nbr + 1;
	if (nbr[0] < '0' || nbr[0] > '9')
	{
		ft_putstr("ERROR\n");
		return (NULL);
	}
	size = size_int(nbr);
	while (size > 1 && nbr[0] == '0')
	{
		size --;
		nbr = nbr + 1;
	}
	return (nbr);
}

int	ft_print_number(char *nbr, int size, char ***dict)
{
	int	size_to_print;
	int	i;

	if (size > 3)
	{
		size_to_print = size % 3;
		if (size_to_print == 0)
			size_to_print = 3;
		i = 0;
		while (nbr[i] == '0' && i < 3)
			i++;
		if (i == 3)
			ft_print_number(nbr + size_to_print, size - size_to_print, dict);
		else
		{
			ft_print_hundred(nbr, size_to_print, dict);
			ft_thousand(nbr + size_to_print, size - size_to_print + 1, dict);
			ft_print_number(nbr + size_to_print, size - size_to_print, dict);
		}
	}
	else
		ft_print_hundred(nbr, size, dict);
	return (1);
}

int	process(char *nbr, char ***dict)
{
	int	size;

	size = size_int(nbr);
	if (size == 1 && nbr[0] == '0')
	{
		ft_put_digit("0", 1, dict);
		ft_putchar(10);
		return (1);
	}
	ft_print_number(nbr, size, dict);
	ft_putchar(10);
	return (1);
}

int	main(int argc, char **argv)
{
	char	***dict;
	char	*number;

	if (argc > 3 || argc == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 3)
		dict = dict_gen(argv[1]);
	else
		dict = dict_gen("numbers.dict");
	if (dict == NULL)
		return (0);
	number = argv[argc - 1];
	number = ft_clean_number(number);
	if (number == NULL)
		return (0);
	process(number, dict);
	ft_free(dict);
	return (0);
}
