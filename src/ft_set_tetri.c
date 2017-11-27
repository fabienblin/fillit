/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_tetri.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 14:37:56 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:42:09 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_figure_dim(char *data, t_tetri *tetri)
{
	int origin;
	int end;

	origin = ft_set_tetri_origin(data);
	end = ft_set_tetri_end(data);
	tetri->x = (end % 5) - (origin % 5) + 1;
	tetri->y = (end / 5) - (origin / 5) + 1;
}

void	ft_copy_tetri_data(t_tetri *tetri, char *data, int origin)
{
	int y;
	int x;

	y = 0;
	while (tetri->data[y])
	{
		x = 0;
		while (tetri->data[y][x])
		{
			tetri->data[y][x] = *(data + origin + x + 5 * y);
			x++;
		}
		y++;
	}
}

t_tetri	*ft_new_tetri(char *data, char order)
{
	t_tetri *tetri;

	if (!data)
		return (NULL);
	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->x = 0;
	tetri->y = 0;
	ft_set_figure_dim(data, tetri);
	if (!(tetri->data = ft_new_grid(tetri->y, tetri->x)))
		return (NULL);
	ft_copy_tetri_data(tetri, data, ft_set_tetri_origin(data));
	tetri->order = order;
	return (tetri);
}

t_list	*ft_get_tetri_lst(int fd, char *buf)
{
	int		read_size;
	t_list	*lst;
	t_tetri	*tetri;
	char	order;

	order = 'A';
	read_size = 1;
	lst = NULL;
	while (read_size > 0)
	{
		if ((read_size = read(fd, buf, 20)) == 20)
		{
			if (!(tetri = ft_new_tetri(buf, order)))
				return (NULL);
			ft_lstpush(&lst, ft_lstnew(tetri, sizeof(t_tetri)));
			order++;
		}
		read(fd, buf, 1);
	}
	if (read_size == -1)
		EXIT;
	return (lst);
}

t_list	*ft_save_tetriminos(char *file_name)
{
	int		fd;
	char	*buf;
	t_list	*lst;

	if (!(buf = ft_strnew(BUFFSIZE)))
		EXIT;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		EXIT;
	lst = ft_get_tetri_lst(fd, buf);
	close(fd);
	free(buf);
	return (lst);
}
