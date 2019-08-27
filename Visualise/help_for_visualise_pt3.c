/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_visualise_pt3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:16:06 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/06 19:37:33 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualise.h"

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

	amount_spaces = ft_count_amount_digits(find_max_data(g_vis_stack_b));
	j = -1;
	while (++j < 100 - indents_for_b)
		write(1, " ", 1);
	ft_printf("%d", g_vis_stack_b->array[i].data);
	j = -1;
	if (g_vis_stack_b->array[i].data < 0)
		j++;
	while (++j < amount_spaces)
		write(1, " ", 1);
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

int		print_stack_a_before_b(int amount_spaces_before,
								int indents_for_b, int i, int k)
{
	int	j;

	j = ft_count_amount_digits(g_vis_stack_a->array[i].data) - 1;
	if (g_vis_stack_a->array[i].data >= -9)
		while (++j < amount_spaces_before)
			write(1, " ", 1);
	ft_printf("%d ", g_vis_stack_a->array[i].data);
	indents_for_b = ft_count_amount_digits(g_vis_stack_a->array[i].data) + 1;
	j = -1;
	while (++j < g_vis_stack_a->array[i].index / k)
		if (g_vis_stack_a->array[i].for_what_changing)
			ft_printf("%{yellow}s", "-");
		else if (g_vis_stack_a->array[i].index + 1 ==
			g_vis_stack_a->array[i - 1].index || i == 0)
			ft_printf("%{green}s", "-");
		else
			write(1, "-", 1);
	indents_for_b += j - 1;
	g_vis_stack_a->array[i].if_changing = 0;
	g_vis_stack_a->array[i].for_what_changing = 0;
	return (indents_for_b);
}

void	print_vis_stacks(int k, char *command)
{
	int	i;
	int	max_stack_size;
	int	amount_spaces_before;
	int	indents_for_b;

	i = -1;
	indents_for_b = 0;
	if (find_min_data(g_vis_stack_a) < 0)
		amount_spaces_before =
						ft_count_amount_digits(find_min_data(g_vis_stack_a));
	else
		amount_spaces_before = 0;
	max_stack_size = ft_max_int(g_vis_stack_a->size, g_vis_stack_b->size);
	while (++i < max_stack_size)
	{
		if (g_vis_stack_a->array[i].index != 0)
			indents_for_b = print_stack_a_before_b(
							amount_spaces_before, indents_for_b, i, k);
		if (g_vis_stack_b->array[i].index != 0)
			print_stack_b_after_a(indents_for_b, k, i);
		write(1, "\n", 1);
	}
	ft_printf("\nCommand = %s\n", command);
}
