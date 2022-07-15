/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:54:42 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/15 17:43:13 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_list	*make_a_lst(t_stack_list *a_lst, \
							size_t quantity, \
							int *compressed_sequence)
{
	t_stack_list	*tent;
	t_stack_list	*tmp_prev;
	size_t			i;

	tent = a_lst;
	tent->num = compressed_sequence[0];
	i = 1;
	while (i < quantity)
	{
		tent->next = (t_stack_list *)malloc(sizeof(t_stack_list));
		if (tent->next == NULL)
			ft_exit(MALLOC_ERROR_MESSAGE);
		tmp_prev = tent;
		tent = tent->next;
		tent->num = compressed_sequence[i];
		tent->prev = tmp_prev;
		i++;
	}
	tent->next = a_lst;
	a_lst->prev = tent;
	return (a_lst);
}
