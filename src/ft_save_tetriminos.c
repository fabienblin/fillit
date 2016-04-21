//lire le fichier tetri par tetri de 20 chars
//concatenner les 4 lignes de chaque tetri sans les \n
//tronquer les tetri pour retirer les points des extremites
//garder dans env->tetri_lst->content la partie tronquee







void	ft_save_tetriminos(t_env *env, char *file_name)
{
	int		fd;
	int		read_ret;
	char	tetri[21];

	fd = open(file_name, O_RDONLY);
	read_ret = 1;
	ft_bzero(tetri, 21);
	while (read_ret)
	{
		read_ret = read(fd, tetri, 20);
	}
}
