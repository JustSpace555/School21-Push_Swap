/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:22 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 20:15:48 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

int	is_sorted(t_vector *stack)
{
	int	i;

	if (stack->size == 0)
		return (1);
	i = ARRAY_SIZE(stack);
	while (i > 0)
	{
		if (stack->vector[i - 1] < stack->vector[i])
			return (0);
		i--;
	}
	return (1);
}
