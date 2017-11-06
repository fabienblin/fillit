#include "../inc/fillit.h"

t_env	*ft_new_env()
{
	t_env	*new;

	if(!(new = (t_env *)malloc(sizeof(*new))))
		return (NULL);
	new->grid_size = 0;
	new->grid = NULL;
	new->tetri_lst = NULL;
	return (new);
}
