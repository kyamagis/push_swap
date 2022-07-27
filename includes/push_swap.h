/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/27 11:57:14 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FD_ERROR "File descriptor error"
# define ARG_ERROR "Too many or too few Arguments"
# define LINE_ERROR "The lines are of uneven length"
# define INVALID_COLOR_CODE "Invalid color code"
# define MALLOC_ERROR "Error\n"
# define NIL -1
# define A 0
# define B 1

# define ERROR "Error"

//# include <libft.h> 
# include "../libft/libft.h"
//# include <get_next_line.h>
# include "../printf/ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_stack_list
{
	struct s_stack_list	*prev;
	int64_t				num;
	struct s_stack_list	*next;
}	t_stack_list;

void			ft_exit(char *error_type);
int64_t			*sequence_compression(size_t quantity, char **argv);
void			quick_sort(int left, int right, int64_t *sequence);
void			make_a_lst(t_stack_list *a_lst, size_t quantity, int64_t *compressed_sequence);
void			make_b_lst_nil_node(t_stack_list *b_lst);
void			ft_push_swap(size_t quantity, t_stack_list	*a_lst, t_stack_list *b_lst);

#endif
