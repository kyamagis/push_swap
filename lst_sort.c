#include <libc.h>

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q a.out");
}

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int compare_data(int a, int b)
{
	return (a <= b);
}

t_list	*sort_lst(t_list *lst, int (*cmp)(int a, int b))
{
	t_list	*tent;
	t_list	*tmp_tent;
	t_list	*tmp_tent_next;
	t_list	*tmp_tent_next_next;

	tent = lst;
	printf("%4p\n%4p\n", lst, tent);
	if (cmp(tent->data, tent->next->data) == 0)
	{
		tmp_tent = tent;
		tmp_tent_next = tent->next;
		tmp_tent_next_next = tent->next->next;
		tent = tent->next;
		tent->next = tmp_tent;
		tmp_tent->next = tmp_tent_next_next;
		printf("%4d, %4d, %4d\n", tent->data, tent->next->data, tent->next->next->data);
	}

	t_list	*sorted_lst;
	sorted_lst = lst;
	while (sorted_lst->next)
	{
		printf("%4d", sorted_lst->data);
		sorted_lst = sorted_lst->next; 
	}
	printf("\n");
	printf("%p\n", lst);
	//printf("%4d", lst->data);
	return (lst);
}

void	free_lst(t_list *lst)
{
	t_list *tmp_next;

	
	while(lst->next)
	{
		
		tmp_next = lst->next;
		free(lst);
		lst = NULL;
		lst = tmp_next;
		
	}
	
}


void	make_sequence(int *sequence, int quantity, char **argv)
{
	int	i = 0;
	
	while (i < quantity)
	{
		sequence[i] = atoi(argv[i + 1]);
		i++;
	}

}

t_list	*make_lst(int *sequence, int quantity)
{
	t_list	*lst = (t_list *)malloc(sizeof(t_list));
	t_list	*tent;
	t_list	*tmp;
	int	i = 0;

	tent = lst;
	while (i < quantity)
	{
		tent->data = sequence[i];
		tmp = (t_list *)malloc(sizeof(t_list));
		tent->next = tmp;
		tent = tent->next;
		tent->next = NULL;
		i++;
	}
	return (lst);
}

int main(int argc, char **argv)
{
	
	int	*sequence;

	if (argc == 1)
	{
		printf("Invalid\n");
		return (0);
	}
	sequence = (int *)malloc(sizeof(int) * argc - 1);
	make_sequence(sequence, argc - 1, argv);
	t_list	*lst;
	lst = make_lst(sequence, argc - 1);

	// int i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("%3d", sequence[i]);
	// 	i++;
	// }
	// printf("\n");
	// t_list	*tent = lst;
	// while (tent->next)
	// {
	// 	printf("%4d", tent->data);
	// 	tent = tent->next; 
	// }
	// printf("\n");

	// t_list	*tmp0;
	// t_list	*tmp2;
	// tmp0 = lst->next;
	// tmp2 = lst->next->next->next;
	// printf("%4d, %4d, %4d\n", lst->next->data, lst->next->next->data, lst->next->next->next->data);
	// lst->next = lst->next->next;
	// printf("%4d, %4d, %4d\n", lst->next->data, lst->next->next->data, lst->next->next->next->data);
	// lst->next->next = tmp0;
	// printf("%4d, %4d, %4d\n", lst->next->data, lst->next->next->data, lst->next->next->next->data);
	// tmp0->next = tmp2;
	// printf("%4d, %4d, %4d\n", lst->next->data, lst->next->next->data, lst->next->next->next->data);

	// t_list	*tmp;
	// t_list	*tmp1;
	// tmp = lst;
	// tmp1 = lst->next->next;
	// printf("%4d, %4d, %4d\n", lst->data, lst->next->data, lst->next->next->data);
	// lst = lst->next;
	// printf("%4d, %4d, %4d\n", lst->data, lst->next->data, lst->next->next->data);
	// lst->next = tmp;
	// printf("%4d, %4d, %4d\n", lst->data, lst->next->data, lst->next->next->data);
	// tmp->next = tmp1;
	// printf("%4d, %4d, %4d\n", lst->data, lst->next->data, lst->next->next->data);

	sort_lst(lst, compare_data);

	// t_list	*sorted_lst;
	// sorted_lst = sort_lst(lst, compare_data);
	// printf("%p\n", sorted_lst);
	
	// while (sorted_lst->next)
	// {
	// 	printf("%4d", sorted_lst->data);
	// 	sorted_lst = sorted_lst->next; 
	// }
	// printf("\n");


	// free_lst(lst);

	exit(0);
}