/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:16:51 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/15 18:14:18 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	a_to_int(size_t quantity, char **argv, int *sequence)
{
	size_t	i;

	if (sequence == NULL)
		ft_exit(ERROR);
	i = 0;
	while (i < quantity)
	{
		sequence[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

static void	detect_duplicate_sequence(size_t quantity, int *sorted_sequence)
{
	size_t	i;

	i = 0;
	while (i + 1 < quantity)
	{
		if (sorted_sequence[i] == sorted_sequence[i + 1])
			ft_exit(ERROR);
		i++;
	}
}

static void	coordinate_compression(size_t quantity, \
									int *sequence, \
									int *sorted_sequence)
{
	size_t	i;
	size_t	compression_num;

	i = 0;
	while (i < quantity)
	{
		compression_num = 0;
		while (1)
		{
			if (sequence[i] == sorted_sequence[compression_num])
			{	
				sequence[i] = (int)compression_num;
				break ;
			}
			compression_num++;
		}
		i++;
	}
}

int	*sequence_compression(size_t quantity, char **argv)
{
	int	*sorted_sequence;
	int	*sequence;

	sorted_sequence = (int *)malloc(sizeof(int) * (quantity));
	if (sorted_sequence == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	a_to_int(quantity, argv, sorted_sequence);
	quick_sort(0, quantity - 1, sorted_sequence);
	detect_duplicate_sequence(quantity, sorted_sequence);
	sequence = (int *)malloc(sizeof(int) * (quantity));
	if (sequence == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	a_to_int(quantity, argv, sequence);
	coordinate_compression(quantity, sequence, sorted_sequence);
	free (sorted_sequence);
	return (sequence);
}
