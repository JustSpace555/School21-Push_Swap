/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_vizualize_pt3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:16:06 by qmebble           #+#    #+#             */
/*   Updated: 2019/10/22 20:30:19 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualize.h"

void	print_vis_array(t_vis_array *stack)
{
	int	i;

	i = -1;
	ft_printf("Data: ");
	if (stack->size == 0)
		ft_printf("NULL");
	else
		while (++i < stack->size)
			ft_printf("%d ", stack->array[i].data);
	i = -1;
	ft_printf("\nIndx: ");
	if (stack->size == 0)
		ft_printf("NULL");
	else
		while (++i < stack->size)
			ft_printf("%d ", stack->array[i].data);
	ft_printf("\n");
}

void	print_stack_b_after_a(int indents_for_b, int k, int i)
{
	int	j;
	int	amount_spaces;
	int	temp;

	temp = find_max_data(g_vis_stack_b);
	amount_spaces = ft_count_amount_characters(&temp, "int");
	j = -1;
	while (++j < (int)(100 - indents_for_b - ft_count_amount_characters(&g_vis_stack_a->array[i].data, "int")))
		write(1, " ", 1);
	ft_printf("%4d ", g_vis_stack_b->array[i].data);
	j = -1;
	while (++j < g_vis_stack_b->array[i].index / k)
	{
		if (g_vis_stack_b->array[i].for_what_changing)
			ft_printf("%{yellow}s", "-");
		else
			write(1, "-", 1);
	}
	g_vis_stack_b->array[i].if_changing = 0;
	g_vis_stack_b->array[i].for_what_changing = 0;
}

void	print_stack_a_before_b(int *indents_for_b, int i, int k)
{
	int	j;

	ft_printf("%4d ", g_vis_stack_a->array[i].data);
	*indents_for_b = 5 - ft_count_amount_characters(&(g_vis_stack_a->array[i].data), "int");
	j = -1;
	while (++j < g_vis_stack_a->array[i].index / k)
		if (g_vis_stack_a->array[i].for_what_changing)
			ft_printf("%{yellow}s", "-");
		else if (g_vis_stack_a->array[i].index + 1 ==
			g_vis_stack_a->array[i - 1].index || i == 0)
			ft_printf("%{green}s", "-");
		else
			write(1, "-", 1);
	*indents_for_b += j;
	g_vis_stack_a->array[i].if_changing = 0;
	g_vis_stack_a->array[i].for_what_changing = 0;
}

void	print_vis_stacks(int k, char *command)
{
	int	i;
	int	max_stack_size;
	int	indents_for_b;

	i = -1;
	indents_for_b = 0;
	max_stack_size = MAX(g_vis_stack_a->size, g_vis_stack_b->size);
	while (++i < max_stack_size)
	{
		if (g_vis_stack_a->array[i].index != 0)
			print_stack_a_before_b(&indents_for_b, i, k);
		if (g_vis_stack_b->array[i].index != 0)
			print_stack_b_after_a(indents_for_b, k, i);
		write(1, "\n", 1);
	}
	ft_printf("\nCommand = %s\n", command);
}
