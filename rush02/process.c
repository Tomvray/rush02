/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:12:07 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 16:26:42 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr.h"

char	***dict_gen(char *dico_name);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_free(char ***dict);
int		size_int(char	*str);

int	ft_print_number(char *nbr, int size, char ***dict)
{
	int	size_to_print;

	if (size > 3)
	{
		size_to_print = size % 3;
		if (size_to_print == 0)
			size_to_print = 3;
		ft_print_hundred(nbr, size_to_print, dict);
		ft_put_thousand(size - size_to_print + 1, dict);
		ft_print_number(nbr + size_to_print, size - size_to_print, dict);
	}
	else if (size == 1 && nbr[0] == '0')
		ft_put_digit("0", 1, dict);
	else
		ft_print_hundred(nbr, size, dict);
	return (1);
}

int	process(char *nbr, char ***dict)
{
	int	size;

	if (nbr[0] == '+')
		nbr = nbr + 1;
	else if (nbr[0] == '-')
	{
		nbr = nbr + 1;
		ft_putstr("minus ");
	}
	size = size_int(nbr);
	while (size > 1 && nbr[0] == '0')
	{
		size --;
		nbr = nbr + 1;
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
	number = argv[argc - 1];
	process(number, dict);
	ft_free(dict);
	return (0);
}
