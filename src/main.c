/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:08:40 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/27 11:56:40 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q push_swap");
}


void	print_a_lst(t_stack_list *lst_down, t_stack_list *lst_up)
{
	int indx = 0; 
	while (lst_down->num != -1)
	{
		printf("%lld ", lst_down->num);
		lst_down = lst_down->next;
		indx++;
	}
	printf("\n");
	indx = 0; 
	while (lst_up->num != -1)
	{
		printf("%lld ", lst_up->num);
		lst_up = lst_up->prev;
		indx++;
	}
	printf("\n");
}




void	ft_exit(char *error_type)
{
	ft_putendl_fd(error_type, 2);
	exit(1);
}


int	main(int argc, char **argv)
{
	int64_t			*compressed_sequence;
	t_stack_list	a_lst;
	t_stack_list	b_lst;

	if (argc == 1)
		ft_exit(ERROR);
	compressed_sequence = sequence_compression(argc - 1, argv);
	make_a_lst(&a_lst, argc - 1, compressed_sequence);
	make_b_lst_nil_node(&b_lst);

	print_a_lst(&a_lst, a_lst.prev->prev);

	
	ft_push_swap(argc - 1, &a_lst, &b_lst);/////////////////////////////////////

	exit(0);
	return (0);
}

/*
__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q push_swap");
}
*/

/*
	int index = 0;
	while (index < argc - 1)
	{
		printf("%d ", compressed_sequence[index]);
		index++;
	}
	printf("\n");
*/



