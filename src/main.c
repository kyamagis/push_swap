/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:08:40 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/15 18:49:56 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q push_swap");
}

void	ft_exit(char *error_type)
{
	ft_putendl_fd(error_type, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	*compressed_sequence;
	t_stack_list	*a_lst;
	t_stack_list	*b_lst;

	if (argc == 1)
		ft_exit(ERROR);
	compressed_sequence = sequence_compression(argc - 1, argv);
	a_lst = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (a_lst == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	make_a_lst(a_lst, argc - 1, compressed_sequence);
	b_lst = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (b_lst == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	//push_swap(argc - 1, a_lst, b_lst);
	

	t_stack_list	*lst_down;
	int indx = 0; 
	lst_down = a_lst;
	while (indx < argc - 1)
	{
		printf("%d ", lst_down->num);
		lst_down = lst_down->next;
		indx++;
	}
	printf("\n");
	t_stack_list	*lst_up;
	indx = 0; 
	lst_up = a_lst->prev;
	while (indx < argc - 1)
	{
		printf("%d ", lst_up->num);
		lst_up = lst_up->prev;
		indx++;
	}
	printf("\n");

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



