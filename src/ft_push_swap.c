/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:33:10 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/27 11:56:46 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	pb(t_stack_list	**a_lst, t_stack_list *b_lst)
// {
// 	t_stack_list	*tmp_a_lst;
// 	// t_stack_list	*tmp_a_lst_next;
// 	// t_stack_list	*tmp_a_lst_prev;

// 	tmp_a_lst = a_lst;
// 	//printf(".%d\n", a_lst->num);
// 	free(a_lst);
// 	a_lst = tmp_a_lst->next;
// 	//printf("..%d, %d\n", tmp_a_lst->num, a_lst->num);
// 	tmp_a_lst->prev->next = a_lst;
// 	//printf("...%d, %d, %d\n", tmp_a_lst->num, a_lst->num, a_lst->prev->next->num);
// 	b_lst = tmp_a_lst;
// 	//printf(".....%d\n", tmp_a_lst->num);

	
// }

// void	push_swap(size_t quantity, t_stack_list	*a_lst, t_stack_list *b_lst)
// {
// 	t_stack_list	*tmp_a_lst;

// 	tmp_a_lst = a_lst;
// 	while (1)
// 	{
// 		printf("++++%d\n", tmp_a_lst->num);
// 		if (tmp_a_lst->num < (int)quantity / 2)
// 			pb(tmp_a_lst, b_lst);
// 		//printf("++++%d\n", tmp_a_lst->num);
// 		if (tmp_a_lst->num == TERMINAL)
// 			break ;
// 		printf("++++%d\n", tmp_a_lst->num);
// 		// printf("++++%d, ", tmp_a_lst->num);
// 		tmp_a_lst = tmp_a_lst->next;
// 		// printf("++++%d", tmp_a_lst->num);
// 		// printf("\n");
		
// 	}
	
// }

// void	pb(t_stack_list	*a_lst, t_stack_list *b_lst)
// {
// 	t_stack_list	*tmp_a_lst;
// 	t_stack_list	*tmp_a_lst_prev;
// 	t_stack_list	*tmp_a_lst_next;

// 	tmp_a_lst = a_lst;
// 	tmp_a_lst_prev = a_lst->prev; 
// 	tmp_a_lst_next = a_lst->next;
	
// 	tmp_a_lst_prev->next = tmp_a_lst_next;
// 	tmp_a_lst_next->prev = tmp_a_lst_prev;
// 	//tmp_a_lst->prev->next = a_lst;
	
// 	b_lst = tmp_a_lst;
// 	//free(tmp_a_lst);
// }



// void	pb(t_stack_list	**a_lst, t_stack_list **b_lst)
// {
// 	t_stack_list	*tmp_a_lst;
// 	t_stack_list	*a_lst_next;
// 	t_stack_list	*a_lst_prev;
// 	t_stack_list	*b_lst_prev;


// 	tmp_a_lst = *a_lst;
// 	a_lst_next = (*a_lst)->next;
// 	a_lst_prev = (*a_lst)->prev;
// 	*a_lst = (*a_lst)->next;
// 	a_lst_prev->next = *a_lst;
// 	(*a_lst)->prev = a_lst_prev;
	
// 	b_lst_prev = (*b_lst)->prev;
// 	(*b_lst)->prev = tmp_a_lst;
// 	tmp_a_lst->next = *b_lst;
// 	tmp_a_lst->prev = b_lst_prev;
// 	b_lst_prev->next = tmp_a_lst;
	
	
// 	t_stack_list	*lst_down1;
// 	lst_down1 = *a_lst;
// 	while (lst_down1->num != NIL)
// 	{
// 		printf("%lld ", lst_down1->num);
// 		lst_down1 = lst_down1->next;
// 	}
// 	printf("\n");
	
// 	t_stack_list	*b_lst2;
// 	b_lst2 = *b_lst;
// 	printf("%lld ", b_lst2->num);
// 	while (b_lst2->num != NIL)
// 	{
// 		printf("%lld ", b_lst2->num);
// 		b_lst2 = b_lst2->next;
// 	}
// 	printf("\n");
// }


void	pb(t_stack_list	**a_lst, t_stack_list **b_lst)
{
	t_stack_list	*tmp_a_lst;
	t_stack_list	*a_lst_prev;
	t_stack_list	*b_lst_prev;

	tmp_a_lst = *a_lst;
	a_lst_prev = (*a_lst)->prev;
	*a_lst = (*a_lst)->next;
	a_lst_prev->next = *a_lst;
	(*a_lst)->prev = a_lst_prev;
	b_lst_prev = (*b_lst)->prev;
	(*b_lst)->prev = tmp_a_lst;
	tmp_a_lst->next = *b_lst;
	b_lst_prev->next = tmp_a_lst;
	tmp_a_lst->prev = b_lst_prev;
	*b_lst = (*b_lst)->prev;
	ft_printf("pb\n");
}

void	pa(t_stack_list	**a_lst, t_stack_list **b_lst)
{
	t_stack_list	*tmp_a_lst;
	t_stack_list	*a_lst_prev;
	t_stack_list	*b_lst_prev;

	tmp_a_lst = *a_lst;
	a_lst_prev = (*a_lst)->prev;
	*a_lst = (*a_lst)->next;
	a_lst_prev->next = *a_lst;
	(*a_lst)->prev = a_lst_prev;
	b_lst_prev = (*b_lst)->prev;
	(*b_lst)->prev = tmp_a_lst;
	tmp_a_lst->next = *b_lst;
	b_lst_prev->next = tmp_a_lst;
	tmp_a_lst->prev = b_lst_prev;
	*b_lst = (*b_lst)->prev;
	ft_printf("pa\n");
}


void	ft_push_swap(size_t quantity, t_stack_list	*a_lst, t_stack_list *b_lst)
{
	while (1)
	{
		while (a_lst->num < (int)quantity / 2 && a_lst->num != NIL)
			pb(&a_lst, &b_lst);
		if (a_lst->num == NIL)
			break ;
		a_lst = a_lst->next;
	}
	a_lst = a_lst->next;
	
	while (1)
	{
		while (b_lst->num != NIL)
			pa(&b_lst, &a_lst);
		if (b_lst->num == NIL)
			break ;
	}
	
	
	t_stack_list	*lst_down1;
	lst_down1 = a_lst;
	while (lst_down1->num != NIL)
	{
		printf("///%lld ", lst_down1->num);
		lst_down1 = lst_down1->next;
	}
	printf("\n");
	
	t_stack_list	*lst_down2;
	lst_down2 = b_lst;
	while (lst_down2->num != NIL)
	{
		printf("///%lld ", lst_down2->num);
		lst_down2 = lst_down2->next;
	}
	printf("\n");
	
}