/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_sort_pt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:43:42 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:51:22 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

int			find_average(t_vector *stack)
{
	int		i;
	float	sum;

	if (stack->size == 0)
		return (0);
	sum = 0;
	i = ARRAY_SIZE(stack);
	while (i >= 0)
	{
		sum += ELEM(stack, i);
		i--;
	}
	return ((int)(sum / stack->size + 0.5));
}

int			find_average_limit(t_vector *stack, int limit)
{
	int		i;
	float	sum;

	if (stack->size == 0)
		return (0);
	sum = 0;
	i = 0;
	while (ELEM(stack, ARRAY_SIZE(stack) - i) <= limit &&
		ELEM(stack, ARRAY_SIZE(stack) - i) != 1)
	{
		sum += ELEM(stack, ARRAY_SIZE(stack) - i);
		i++;
	}
	return ((int)(sum / i + 0.5));
}

void		split_to_b(int size)
{
	int	avg;
	int	i;

	avg = find_average(g_stack_a);
	i = 0;
	while (i < size)
	{
		if (TOP_ELEM(g_stack_a) < avg)
			push(g_stack_b, g_stack_a, "pb");
		else
			rotate(g_stack_a, "ra");
		i++;
	}
}

void		max_in_b_to_a(void)
{
	int	max_elem;
	int	i;

	i = 0;
	max_elem = ft_find_max(g_stack_b);
	if (max_elem == TOP_ELEM(g_stack_b))
		push(g_stack_a, g_stack_b, "pa");
	else
	{
		if (TOP_ELEM(g_stack_b) == g_stack_a->vector[0] + 1
			|| TOP_ELEM(g_stack_b) == 1)
		{
			push(g_stack_a, g_stack_b, "pa");
			rotate(g_stack_a, "ra");
		}
		else
		{
			while (ELEM(g_stack_b, i) != max_elem)
				i++;
			if (i <= (ARRAY_SIZE(g_stack_b) + 1) / 2)
				reverse_rotate(g_stack_b, "rrb");
			else
				rotate(g_stack_b, "rb");
		}
	}
}

void		split_to_a(int size)
{
	int	avg;

	avg = find_average(g_stack_b);
	while (size-- > 0)
	{
		if (g_stack_b->size <= 13)
			max_in_b_to_a();
		else
		{
			if (TOP_ELEM(g_stack_b) >= avg)
				push(g_stack_a, g_stack_b, "pa");
			else
			{
				if (TOP_ELEM(g_stack_b) == (g_stack_a)->vector[0] + 1
					|| TOP_ELEM(g_stack_b) == 1)
				{
					push(g_stack_a, g_stack_b, "pa");
					rotate(g_stack_a, "ra");
				}
				else
					rotate(g_stack_b, "rb");
			}
		}
	}
}
