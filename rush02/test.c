#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int	size_int(char	*str)
{
	int	i;

	i = 0;
	while (str[i] <= '9' && str[i] >=  '0')
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
void	ft_free(char ***dict)
{
	int	k;

	k = 0;
	while (dict[k] != NULL)
	{
		free(dict[k][0]);
		free(dict[k][1]);
		free(dict[k]);
		k++;
	}
	free(dict[k]);
	free(dict);
}

char	***data_dict(char *str)
{
	int i;
	int	j;
	int	k;
	char	***res;
	char	*str_dict;
	char	*str_dict2;


	i = 0;
	k = 0;
	res = malloc(sizeof(*res) * 42);
	while(k < 41)
	{
		res[k] = malloc(sizeof(**res) * 2);
		str_dict = malloc(sizeof(char) * (size_int(str + i) + 1));
		j = 0;
		while (str[i] <= '9' && str[i] >=  '0')
		{
			str_dict[j] = str[i];
			i++;
			j++;
		}
		str_dict[j] = 0;
		res[k][0] = str_dict;
		printf("int %s \n", res[k][0]);
		while(str[i] == ' ' || str[i] == ':')
			i++;
		j = 0;
		str_dict = malloc(sizeof(char) * (ft_strlen(str + i)) + 1);
		while(str[i] != 10)
		{
			str_dict[j] = str[i];
			i++;
			j++;
		}
		str_dict[j] = 0;
		res[k][1] = str_dict;
		printf("nbr %s \n", res[k][1]);
		k++;
		i++;
	}
	res[k] = NULL;
	return (res);
}

int ft_size_file(char *file_name)
{
	int 	fd;
	int 	bufsize = 100;
	int		ret;
	int		file_size;
    char    buf[bufsize + 1];

	fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        printf("OPEN() Failed");
        return (0);
    }
    file_size = 0;
    ret = read(fd, buf, bufsize);
    while(ret)
    {
        file_size += ret;
        ret = read(fd, buf, bufsize);
    }
	close(fd);
	return(file_size);
}

char ***dict_gen(char *dico_name)
{
    int fd;
    int file_size;
    int ret;
    char    *str;
	char	***dict;

	file_size = ft_size_file(dico_name);
	fd = open(dico_name, O_RDONLY);
    if (fd == -1)
    {
        printf("OPEN() Failed");
        return (0);
    }
	str = malloc(sizeof(char) * (file_size + 1));
	if (str == NULL)
    {
    	printf("ERROR");
		return (0);
    }
    ret = read(fd, str, file_size);
	str[file_size] = 0;
	close(fd);
	dict = data_dict(str);
    return (dict);
}