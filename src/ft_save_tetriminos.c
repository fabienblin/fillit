#include "../inc/fillit.h"

t_tetri *new_tetri(char *data, char order)
{
	t_tetri *tetri;
	int i;

	if(!data || !order)
		return(NULL);
	if(!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return(NULL);
	i = 0;
	while(i < 4)
	{
		ft_memcpy(tetri->data[i], (data + 4 * i + i), 4);
		i++;
	}
	tetri->order = order;
	return(tetri);
}

/*
void	ft_save_tetriminosOLD(t_env *env, char *file_name)
{
	int fd;
	int read_size;
	char *buf;
	char *bufcpy;
	char order;
	int read_total;
	t_list *tetri_lst;
	t_tetri *tetri;

	if(!(buf = ft_strnew(BUFFSIZE)))
		ft_exit("buf malloc bug");
	if ((fd = open(file_name,  O_RDONLY)) == -1)
		ft_exit(strerror(errno));

	order = 'A';
	read_total = 0;
	if(!(bufcpy = ft_strnew(BUFFSIZE)))
		ft_exit("bufcpy malloc bug");

	read_size = 1;

	//reads file
	while(read_size > 0)
	{
		// reads 1 tetri
		while(read_total < BUFFSIZE && read_size > 0)
		{
			printf("###################################");
			if((read_size = read(fd, buf, BUFFSIZE - read_total)) > 0)
			{
				strncpy(bufcpy + read_total, buf, read_size);
				read_total += read_size;
			}
			if(read_size == 0)
				printf("End of file reading.");
			else if (read_size == -1)
				ft_exit(strerror(errno));
		}
		if(!(tetri = new_tetri(bufcpy, order)))
			ft_exit("tetri malloc bug");
		// save tetri in list and save env
		ft_lstadd(t_list **alst, t_list *new);
		if(!(tetri_lst = ft_lstnew(tetri, sizeof(t_tetri))))
			ft_exit("tetri_lst malloc bug");
		tetri_lst->data = tetri;
		env->tetri_lst = tetri_lst;
		tetri_lst = tetri_lst->next;

		printf("%sread_size=%d\nBUFFSIZE=%d\n",bufcpy, read_size, BUFFSIZE);
	}
	free(bufcpy);

	close(fd);
}
*/
t_list	*ft_save_tetriminos(char *file_name)
{
	//read file and get each tetriminos
	t_list	*lst;
	t_tetri	*tetri;
	int		read_size;
	int		read_i;
	int		fd;
	char	*buf;
	char	order;

	if(!(buf = ft_strnew(BUFFSIZE)))
		ft_exit("a");
	if ((fd = open(file_name,  O_RDONLY)) == -1)
		ft_exit(strerror(errno));
	order = 'A';
	read_size = 1;
	lst=NULL;
	//read entire file
	while(read_size > 0)
	{
		//read 1 tetriminos
		read_i = 0;
		while(read_i < BUFFSIZE && read_size > 0)
		{
			read_size = read(fd, buf+read_i, BUFFSIZE - read_i);
			read_i += read_size;
		}
	//	printf("order=%c\n", order);
	//	printf("buf=\n%s\n", buf);
		//add tetriminos to list
		tetri = new_tetri(buf, order);
		ft_lstadd(&lst, ft_lstnew(tetri, sizeof(t_tetri)));
		order++;
		//skip empty line
		if(read_i == BUFFSIZE)
			read(fd, buf, 1);
	}
	if(read_size == -1)
		ft_exit("b");

	//printf list
	t_list *l = lst;
	while(l)
	{
		printf("order=%c\n", ((t_tetri *)l->content)->order);
		printf("teri=\n");
		int i;
		int j;
		for(i = 0; i<4; i++)
		{
			for(j = 0; j<4; j++)
			{
				printf("%c",((t_tetri *)l->content)->data[i][j]);
			}
			printf("$\n");
		}
		printf("\n");
		l = l->next;
	}
	close(fd);
	return(lst);
}

void set_env(t_env *env, char *file_name)
{
	env->tetri_lst = ft_save_tetriminos(file_name);
}
