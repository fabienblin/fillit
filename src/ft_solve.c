#include "../inc/fillit.h"
#define LEN 4

void printflst(t_list *lst) {
	while(lst)
	{
		printf("%c", ((t_tetri *)lst->content)->order);
		lst = lst->next;
	}
	printf("\n");
}

void ft_swapptr(void **a, void **b)
{
	void *tmp;

	if(a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

t_list *ft_getlst(t_list *lst, int i)
{
	t_list *getlst;
	int j;

	getlst = lst;
	j = 0;
	while(j < i)
	{
		getlst = getlst->next;
		j++;
	}
	return (getlst);
}

void ft_permute(t_list *lst, int a, int n)
{
	int i;
	void *A;
	void *B;

	if(n == a)
	{
		//printflst(lst);
	}
	else
	{
		i = 0;
		while(i < n - a)
		{
			A = ft_getlst(lst, a);
			B = ft_getlst(lst, a + i);
			ft_swapptr(&A, &B);
			ft_permute(lst, a + 1, n);
			ft_swapptr(&A, &B);
			i++;
		}
	}
}

int	ft_solve(t_env *env)
{
	int len = LEN;
	t_list *lst = env->tetri_lst;
	ft_permute(lst, 0, len);
	//printflst(lst);
	return (0);
}
