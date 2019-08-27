/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:49 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:58:16 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void	rotate_min(t_vector *stack)
{
	int	i;
	int	min;

	min = ft_find_min(stack);
	i = -1;
	while (++i < ARRAY_SIZE(stack))
		if (ELEM(stack, i) == min)
			break ;
	if (i <= stack->size / 2)
		reverse_rotate(g_stack_a, "rra");
	else
		rotate(g_stack_a, "ra");
}

void	five_situation(void)
{
	int	avg;

	avg = find_average(g_stack_a);
	while (ft_find_min(g_stack_a) < avg)
	{
		if (TOP_ELEM(g_stack_a) < avg)
		{
			if (ELEM(g_stack_a, 0) + 1 == TOP_ELEM(g_stack_a))
			{
				rotate_min(g_stack_a);
				if (is_sorted(g_stack_a))
					return ;
			}
			push(g_stack_b, g_stack_a, "pb");
		}
		else
			rotate_min(g_stack_a);
	}
}

void	sort_a(void)
{
	int	i;

	i = ARRAY_SIZE(g_stack_a) + 1;
	while (--i > 0)
	{
		if (ELEM(g_stack_a, ARRAY_SIZE(g_stack_a) - 1) == ft_find_min(g_stack_a)
			&& TOP_ELEM(g_stack_a) == ft_find_max(g_stack_a))
			rotate(g_stack_a, "ra");
		if (ELEM(g_stack_a, i - 1) < ELEM(g_stack_a, i))
		{
			while (i < ARRAY_SIZE(g_stack_a))
			{
				rotate(g_stack_a, "ra");
				i++;
			}
			if (ELEM(g_stack_a, ARRAY_SIZE(g_stack_a) - 1) ==
					ft_find_min(g_stack_a) &&
					TOP_ELEM(g_stack_a) == ft_find_max(g_stack_a))
				rotate(g_stack_a, "ra");
			else
				swap(g_stack_a, "sa");
		}
	}
}

void	sort_b(void)
{
	int	i;

	i = ARRAY_SIZE(g_stack_b) + 1;
	while (--i > 0)
	{
		if (TOP_ELEM(g_stack_b) == ft_find_min(g_stack_b)
				&& ELEM(g_stack_b, ARRAY_SIZE(g_stack_b) - 1)
				== ft_find_max(g_stack_b))
			rotate(g_stack_b, "rb");
		if (ELEM(g_stack_b, i - 1) > ELEM(g_stack_b, i))
		{
			while (i < ARRAY_SIZE(g_stack_b))
			{
				rotate(g_stack_b, "rb");
				i++;
			}
			if (TOP_ELEM(g_stack_b) == ft_find_min(g_stack_b) &&
					ELEM(g_stack_b, ARRAY_SIZE(g_stack_b) - 1) ==
					ft_find_max(g_stack_b))
				rotate(g_stack_b, "rb");
			else
				swap(g_stack_b, "sb");
		}
	}
}

void	sort_simple(void)
{
	if (is_sorted(g_stack_a))
		return ;
	make_new_stack(&g_stack_b, g_stack_a->size);
	if (g_stack_a->size > 4)
		five_situation();
	if (g_stack_a->size > 0)
		sort_a();
	if (g_stack_b->size > 0)
		sort_b();
	while (g_stack_b->size > 0)
		push(g_stack_a, g_stack_b, "pa");
}
