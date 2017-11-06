#include "../inc/fillit.h"

void	ft_lstpush(t_list **lst, t_list *new)
{
  if(!*lst)
  {
    *lst = new;
  }
  else
  {
    ft_lstpush(&(*lst)->next, new);
  }
}

t_tetri	*ft_new_tetri(char *data, char order)
{
	t_tetri *tetri;
	int i;

	if(!data)
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
  //tetri->mark = 0;
	return (tetri);
}

t_list	*ft_get_tetri_lst(int fd, char *buf)
{
	int		read_size;
	int		read_i;
	t_list	*lst;
	t_tetri	*tetri;
	char	order;

	order = 'A';
	read_size = 1;
	lst=NULL;
	while(read_size > 0)
	{
		read_i = 0;
		while(read_i < BUFFSIZE && read_size > 0)
		{
			read_size = read(fd, buf + read_i, BUFFSIZE - read_i);
			read_i += read_size;
    }
    if(read_size > 0)
    {
      if(!(tetri = ft_new_tetri(buf, order)))
        return (NULL);
      ft_lstpush(&lst, ft_lstnew(tetri, sizeof(t_tetri)));
      order++;
      if(read_i == BUFFSIZE)
        read(fd, buf, 1);
    }
	}
	if(read_size == -1)
		EXIT;
	return (lst);
}

t_list	*ft_save_tetriminos(char *file_name)
{
	int		fd;
	char	*buf;
	t_list	*lst;

	if(!(buf = ft_strnew(BUFFSIZE)))
		EXIT;
	if ((fd = open(file_name,  O_RDONLY)) == -1)
		ft_exit(strerror(errno));
	lst = ft_get_tetri_lst(fd, buf);
	close(fd);
	return (lst);
}
