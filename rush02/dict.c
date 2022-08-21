/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:28:58 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 15:48:26 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_error.h"
#include "ft_str.h"

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

int	ft_count_raws(char *str)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == 10)
			nbr++;
		i++;
	}
	return (nbr);
}

char	***data_dict(char *str, int n_raws)
{
	int		i;
	int		k;
	char	***res;

	i = 0;
	k = -1;
	res = malloc(sizeof(*res) * (n_raws + 1));
	if (res == NULL)
		return (NULL);
	while (++k < n_raws)
	{
		res[k] = malloc(sizeof(**res) * 2);
		if (res[k] == NULL)
			return (NULL);
		res[k][0] = ft_strncpy(str + i, size_int(str + i));
		i += size_int(str + i);
		while (str[i] == ' ' || str[i] == ':')
			i++;
		res[k][1] = ft_strncpy(str + i, ft_strlen(str + i));
		i += ft_strlen(str + i);
		i++;
	}
	res[k] = NULL;
	return (res);
}

int	ft_size_file(char *file_name)
{
	int		fd;
	int		ret;
	int		file_size;
	char	buf[101];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write (1, "OPEN FAILED\n", 12);
		return (0);
	}
	file_size = 0;
	ret = read(fd, buf, 100);
	while (ret)
	{
		file_size += ret;
		ret = read(fd, buf, 100);
	}
	close(fd);
	return (file_size);
}

char	***dict_gen(char *dict_name)
{
	int		fd;
	int		file_size;
	int		ret;
	char	*str;
	char	***dict;

	file_size = ft_size_file(dict_name);
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		return (ft_openfailed());
	str = malloc(sizeof(char) * (file_size + 1));
	if (str == NULL)
		return (ft_error());
	ret = read(fd, str, file_size);
	str[file_size] = 0;
	close(fd);
	if (ft_ctrldict_error(str, 0) == 0)
		return (0);
	dict = data_dict(str, ft_count_raws(str));
	free(str);
	return (dict);
}
