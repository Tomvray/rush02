

char ***dict_gen(char *dico_name);
int	size_int(char	*str);
void    ft_putstr(char *str);
void	ft_putchar(char);
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
	if (size == 2 && nbr[i])
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

int process(char *nbr, char ***dict)
{
    int i;
    int size;

    size = size_int(nbr);
	
    ft_print_hundred(nbr, 3, dict);
	return (1);
}

int main(int argc, char **argv)
{
    char ***dict;
    char *number;

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