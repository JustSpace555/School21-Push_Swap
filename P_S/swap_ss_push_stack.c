/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ss_push_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:55 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 19:15:56 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void	swap(t_vector *stack, char *str)
{
	int	temp;

	if (!stack || stack->size <= 1 || !stack->vector)
		return ;
	temp = TOP_ELEM(stack);
	TOP_ELEM(stack) = stack->vector[stack->size - 2];
	stack->vector[stack->size - 2] = temp;
	if (str)
	{
		write(1, str, 2);
		write(1, "\n", 1);
	}
}

void	ss(char *str)
{
	swap(g_stack_a, NULL);
	swap(g_stack_b, NULL);
	if (str)
		write(1, "ss\n", 3);
}

void	push(t_vector *dest, t_vector *src, char *str)
{
	if (!src || src->size == 0)
		return ;
	if (!dest)
		make_new_stack(&dest, src->size);
	dest->vector[dest->size] = TOP_ELEM(src);
	dest->size++;
	TOP_ELEM(src) = 0;
	src->size--;
	if (str)
	{
		write(1, str, 2);
		write(1, "\n", 1);
	}
}
