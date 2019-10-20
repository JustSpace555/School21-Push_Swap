/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualize_commands_pt1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:36:27 by qmebble           #+#    #+#             */
/*   Updated: 2019/10/20 20:04:43 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualize.h"

void	swap_vis(t_vis_array *stack)
{
	t_vis_element	temp;

	if (!stack || stack->size <= 1 || !stack->array)
		return ;
	TOP_VIS_ELEM(stack).if_changing = 1;
	temp = TOP_VIS_ELEM(stack);
	TOP_VIS_ELEM(stack) = VIS_ELEM(stack, ARRAY_SIZE(stack) - 1);
	VIS_ELEM(stack, ARRAY_SIZE(stack) - 1) = temp;
	TOP_VIS_ELEM(stack).for_what_changing = 1;
}

void	ss_vis(void)
{
	swap_vis(g_vis_stack_a);
	swap_vis(g_vis_stack_b);
}

void	push_vis(t_vis_array *dest, t_vis_array *src)
{
	if (!src || src->size == 0)
		return ;
	VIS_ELEM(dest, dest->size) = TOP_VIS_ELEM(src);
	dest->size++;
	TOP_VIS_ELEM(dest).for_what_changing = 1;
	TOP_VIS_ELEM(src).index = 0;
	TOP_VIS_ELEM(src).data = 0;
	src->size--;
}
