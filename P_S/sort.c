/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:52 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:44:11 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void		ft_push_swap(void)
{
	int	max;

	if (g_stack_b->size == 0)
		return ;
	max = ft_find_max(g_stack_b);
	split_to_a(g_stack_b->size);
	while ((TOP_ELEM(g_stack_a) == ELEM(g_stack_a, 0) + 1 ||
			TOP_ELEM(g_stack_a) == 1) && !is_sorted(g_stack_a))
		rotate(g_stack_a, "ra");
	ft_push_swap();
	if (find_lasts_elements(g_stack_a, max) >= 20)
		sort_with_split(max);
	sort_without_split(max);
}

void		sort_without_split(int max)
{
	while (TOP_ELEM(g_stack_a) <= max && TOP_ELEM(g_stack_a) != 1)
		if (TOP_ELEM(g_stack_a) == ELEM(g_stack_a, 0) + 1)
			rotate(g_stack_a, "ra");
		else
			push(g_stack_b, g_stack_a, "pb");
	if (ft_find_min(g_stack_b) == ELEM(g_stack_a, 0) + 1)
		ft_push_swap();
}

void		sort_with_split(int max)
{
	int	amount_of_rotate;
	int	avg;
	int	new_max;
	int	i;

	amount_of_rotate = 0;
	avg = find_average_limit(g_stack_a, max);
	while (TOP_ELEM(g_stack_a) <= max && TOP_ELEM(g_stack_a) != 1)
		if (TOP_ELEM(g_stack_a) >= avg)
		{
			rotate(g_stack_a, "ra");
			amount_of_rotate++;
		}
		else
			push(g_stack_b, g_stack_a, "pb");
	i = -1;
	new_max = ft_find_max(g_stack_b);
	while (++i < amount_of_rotate)
		if (TOP_ELEM(g_stack_b) != new_max)
			rrr("rrr");
		else
			reverse_rotate(g_stack_a, "rra");
	if (ft_find_min(g_stack_b) == ELEM(g_stack_a, 0) + 1
			&& amount_of_rotate > 0)
		ft_push_swap();
}

void		sort_in_progress(void)
{
	if (is_sorted(g_stack_a))
		return ;
	split_to_b(g_stack_a->size);
	ft_push_swap();
	if (find_lasts_elements(g_stack_a, ft_find_max(g_stack_a)) >= 20)
	{
		sort_with_split(ft_find_max(g_stack_a));
		sort_with_split(ft_find_max(g_stack_a));
	}
	sort_without_split(ft_find_max(g_stack_a));
}

void		sort(void)
{
	int	i;

	if (is_sorted(g_stack_a))
		return ;
	make_new_stack(&g_stack_b, g_stack_a->size);
	i = -1;
	while (++i < g_stack_a->size)
	{
		g_stack_b->vector[i] = g_stack_a->vector[i];
		g_stack_b->size++;
	}
	quicksort(0, ARRAY_SIZE(g_stack_b));
	make_indexes(&g_stack_a, &g_stack_b);
	sort_in_progress();
}
