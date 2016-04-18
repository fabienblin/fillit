#include "../inc/fillit.h"

void	ft_valid_count(char *tetri)
{
	int		count_full;
	int		count_empt;
	int		count_retu;
	int		i;

	count_full = 0;
	count_empt = 0;
	count_retu = 0;
	i = ft_strlen(tetri);
	while (i--)
	{
		if (tetri[i] == '#')
			count_full++;
		if (tetri[i] == '.')
			count_empt++;
		if (tetri[i] == '\n')
			count_retu++;
	}
	if ((count_full != 4) 
		|| (count_empt != 12) 
		|| (count_retu != 4))
	{
		ft_putendl("valid_count failed");
		EXIT;
	}
}

void	ft_valid_length(char *tetri)
{
	int		len;
	int		i;

	len = ft_strlen(tetri);
	i = 0;
	while (i < len)
	{
		if ((i % 5) < 4)
		{
			if (!(tetri[i] == '#' || tetri[i] == '.'))
			{		ft_putendl("valid_length b failed");
				EXIT;
			}
		}
		else if (!(tetri[i] == '\n'))
		{		ft_putendl("valid_length c failed");
			EXIT;
		}
		i++;
	}
}

int		ft_element_is_valid(char **elements, char *subject)
{
	int i;
	int	ret;

	i = 4;
	ret = 0;
	while (i--)
	{
		if (subject + 1 == elements[i])
			ret += 1;
		else if (subject + 5 == elements[i])
			ret += 1;
	}
	return (ret);
}

void	ft_valid_figure(char *tetri)
{
	char *elements[4];
	int	i;
	int	valid;
	char *tetri_test = tetri;

	i = 0;
	while(*tetri)
	{
		if (*tetri == '#')
			elements[i++] = tetri;
		tetri++;
	}
	i = 0;
	valid = 0;
	while (i < 4)
	{
		valid += ft_element_is_valid(elements, elements[i]);
		i++;
	}
	if (valid < 3)
	{
		printf("valid_figure fail : valid = %d on tetri : \n%s\n", valid, tetri_test);
		EXIT;
	}
}

void	ft_test_input(char *file_name)
{
	char	tetri[20];
	int		fd;
	int		read_ret;

	fd = open(file_name, O_RDONLY);
	read_ret = 1;
	while (read_ret == 1)
	{
		//tester le nombre de #
		//tester la longueur de chaque ligne
		//tester le nombre de lignes
		//tester le \n final
		//tester que la forme soit juste
		read_ret = read(fd, tetri, 20);
		ft_valid_count(tetri);
		ft_valid_length(tetri);
		ft_valid_figure(tetri);
		read_ret = read(fd, tetri, 1);
		if (read_ret && *tetri != '\n')
			EXIT;
	}
	if (read_ret == -1)
	{
		ft_putendl("test_input failed");
		EXIT;
	}
	else if (read_ret == 0)
		close(fd);
}

