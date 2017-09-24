#include "../inc/fillit.h"

t_tetri *new_tetri(char *data, char order_letter)
{
	t_tetri *tetri;
	int i;

	if(!data || !order_letter)
		return(NULL);
	if(!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return(NULL);
	i = 0;
	while(i < BUFFSIZE)
	{
		if(data + i == '\n')
			i++;
		tetri->data[i/4][i%4] = data + i;
		i++;
	}
	tetri->order_letter = order_letter;
	return(tetri);
}
