/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:42:49 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:43:18 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

int			ft_find_max(t_vector *stack)
{
	int	i;
	int	max;

	if (stack->size == 0)
		return (0);
	max = -MAX_INT - 1;
	i = -1;
	while (++i < stack->size)
		if (max < ELEM(stack, i))
			max = ELEM(stack, i);
	return (max);
}

int			ft_find_min(t_vector *stack)
{
	int	i;
	int	min;

	if (stack->size == 0)
		return (0);
	min = MAX_INT;
	i = -1;
	while (++i < stack->size)
		if (min > ELEM(stack, i))
			min = ELEM(stack, i);
	return (min);
}

int			find_lasts_elements(t_vector *stack, int limit)
{
	int	i;

	i = 0;
	while (i >= 0 && ELEM(stack, ARRAY_SIZE(stack) - i) <= limit &&
			ELEM(stack, ARRAY_SIZE(stack) - i) != 1)
		i++;
	return (i);
}

void		make_indexes(t_vector **stack_a, t_vector **stack_b)
{
	int	i;
	int	j;

	i = ARRAY_SIZE(*stack_a);
	while (i >= 0)
	{
		j = 0;
		while (j < ARRAY_SIZE(*stack_b))
		{
			if (ELEM(*stack_b, j) == ELEM(*stack_a, i) &&
				ELEM(*stack_b, j) != -MAX_INT - 1)
			{
				ELEM(*stack_b, j) = -MAX_INT - 1;
				break ;
			}
			j++;
		}
		ELEM(*stack_a, i) = j + 1;
		i--;
	}
	i = 0;
	(*stack_b)->size = 0;
}

void		quicksort(int left, int right)
{
	int	p;
	int	temp_l;
	int	temp_r;
	int	temp_el;

	temp_l = left;
	temp_r = right;
	p = ELEM(g_stack_b, (left + right) / 2);
	while (ELEM(g_stack_b, left) < p)
		left++;
	while (ELEM(g_stack_b, right) > p)
		right--;
	if (left <= right)
	{
		temp_el = ELEM(g_stack_b, right);
		ELEM(g_stack_b, right) = ELEM(g_stack_b, left);
		ELEM(g_stack_b, left) = temp_el;
		left++;
		right--;
	}
	if (temp_l < right)
		quicksort(temp_l, right);
	if (temp_r > left)
		quicksort(left, temp_r);
}
