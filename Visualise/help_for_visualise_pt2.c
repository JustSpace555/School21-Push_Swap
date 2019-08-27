/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_visualise_pt2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:57:02 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/06 19:36:04 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualise.h"

void		make_vis_stack_a(int *temp)
{
	int	i;

	i = -1;
	while (++i < g_stack_a->size)
	{
		g_vis_stack_a->array[i].data = temp[i];
		g_vis_stack_a->array[i].index = g_stack_a->vector[i];
		g_vis_stack_a->size++;
	}
}

t_vis_array	*make_new_vis_stack(void)
{
	t_vis_array	*stack;

	stack = (t_vis_array *)malloc(sizeof(t_vis_array));
	stack->size = 0;
	stack->array = NULL;
	return (stack);
}

void		make_new_vis_stack_array(t_vis_array *stack, int size)
{
	int	i;

	if (!(stack->array = (t_vis_element *)malloc(sizeof(t_vis_array) * size)))
		return ;
	i = -1;
	while (++i < size)
	{
		stack->array[i].index = 0;
		stack->array[i].data = 0;
		stack->array[i].if_changing = 0;
		stack->array[i].for_what_changing = 0;
	}
	stack->size = 0;
}

void		copy_elements_to_temp_array(int **temp, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		(*temp)[i] = g_stack_b->vector[i];
}

void		free_all(void)
{
	free(g_vis_stack_a->array);
	free(g_vis_stack_b->array);
	free(g_stack_a->vector);
	free(g_stack_b->vector);
	free(g_vis_stack_a);
	free(g_vis_stack_b);
	free(g_stack_a);
	free(g_stack_b);
}
