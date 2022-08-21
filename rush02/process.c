char	***dict_gen(char *dico_name);
int	size_int(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_free(char ***dict);

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
