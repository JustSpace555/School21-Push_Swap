/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr_free_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:45 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/06 18:54:02 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void	reverse_rotate(t_vector *stack, char *str)
{
	int	i;
	int	temp;

	if (!stack || stack->size <= 1 || !stack->vector)
		return ;
	i = 0;
	temp = ELEM(stack, 0);
	while (i < ARRAY_SIZE(stack))
	{
		ELEM(stack, i) = ELEM(stack, i + 1);
		i++;
	}
	TOP_ELEM(stack) = temp;
	if (str)
	{
		write(1, str, 3);
		write(1, "\n", 1);
	}
}

void	rrr(char *str)
{
	reverse_rotate(g_stack_a, NULL);
	reverse_rotate(g_stack_b, NULL);
	if (str)
		write(1, "rrr\n", 4);
}

void	rotate(t_vector *stack, char *str)
{
	int	temp;
	int	i;

	if (!stack || stack->size <= 1 || !stack->vector)
		return ;
	temp = TOP_ELEM(stack);
	i = ARRAY_SIZE(stack);
	while (i >= 1)
	{
		ELEM(stack, i) = ELEM(stack, i - 1);
		i--;
	}
	stack->vector[0] = temp;
	if (str)
	{
		write(1, str, 2);
		write(1, "\n", 1);
	}
}

void	rr(char *str)
{
	rotate(g_stack_a, NULL);
	rotate(g_stack_b, NULL);
	if (str)
		write(1, "rr\n", 3);
}

void	free_stack(t_vector **stack)
{
	int	i;

	if (!stack || !*stack)
		return ;
	i = 0;
	if ((*stack)->vector)
		free((*stack)->vector);
	(*stack)->size = 0;
	free(*stack);
}
