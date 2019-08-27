/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise_commands_pt2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:12:49 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/06 18:16:03 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualise.h"

void	reverse_rotate_vis(t_vis_array *stack)
{
	int				i;
	t_vis_element	temp;

	if (!stack || stack->size <= 1)
		return ;
	i = -1;
	temp = VIS_ELEM(stack, 0);
	temp.for_what_changing = 1;
	while (++i < ARRAY_VIS_SIZE(stack))
		VIS_ELEM(stack, i) = VIS_ELEM(stack, i + 1);
	TOP_VIS_ELEM(stack) = temp;
}

void	rrr_vis(void)
{
	reverse_rotate_vis(g_vis_stack_a);
	reverse_rotate_vis(g_vis_stack_b);
}

void	rotate_vis(t_vis_array *stack)
{
	t_vis_element	temp;
	int				i;

	if (!stack || stack->size <= 1)
		return ;
	temp = TOP_VIS_ELEM(stack);
	temp.for_what_changing = 1;
	i = ARRAY_SIZE(stack);
	while (i >= 1)
	{
		VIS_ELEM(stack, i) = VIS_ELEM(stack, i - 1);
		i--;
	}
	VIS_ELEM(stack, 0) = temp;
}

void	rr_vis(void)
{
	rotate_vis(g_vis_stack_a);
	rotate_vis(g_vis_stack_b);
}
