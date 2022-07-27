/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:16:51 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/26 19:24:00 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	whether_already_sorted(size_t quantity, int64_t *sequence)
{
	size_t		i;
	int64_t		prev_num;

	i = 1;
	prev_num = sequence[0];
	while (i < quantity)
	{
		if (sequence[i] < prev_num)
			return ;
		prev_num = sequence[i];
		i++;
	}
	exit(1);
}

static void	a_to_int(size_t quantity, char **argv, int64_t *sequence)
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

static void	detect_duplicate_sequence(size_t quantity, int64_t *sorted_sequence)
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
									int64_t *sequence, \
									int64_t *sorted_sequence)
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
				sequence[i] = (int64_t)compression_num;
				break ;
			}
			compression_num++;
		}
		i++;
	}
}

int64_t	*sequence_compression(size_t quantity, char **argv)
{
	int64_t	*sorted_sequence;
	int64_t	*sequence;

	if (quantity == 1)
		exit(1);
	sorted_sequence = (int64_t *)malloc(sizeof(int64_t) * (quantity));
	if (sorted_sequence == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	a_to_int(quantity, argv, sorted_sequence);
	whether_already_sorted(quantity, sorted_sequence);
	quick_sort(0, quantity - 1, sorted_sequence);
	detect_duplicate_sequence(quantity, sorted_sequence);
	sequence = (int64_t *)malloc(sizeof(int64_t) * (quantity));
	if (sequence == NULL)
		ft_exit(MALLOC_ERROR_MESSAGE);
	a_to_int(quantity, argv, sequence);
	coordinate_compression(quantity, sequence, sorted_sequence);
	free (sorted_sequence);
	return (sequence);
}
