/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:39 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 19:15:39 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void	print_stack(t_vector *stack, char stack_letter)
{
	int	i;

	ft_printf("%c: ", stack_letter);
	if (!stack || stack->size == 0)
	{
		write(1, "NULL\n", 5);
		return ;
	}
	i = -1;
	while (++i < stack->size)
		ft_printf("%d ", stack->vector[i]);
	printf("\n");
}
