/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:28 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 19:15:29 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void	make_new_stack(t_vector **stack, int amount)
{
	*stack = (t_vector *)malloc(sizeof(t_vector));
	(*stack)->vector = (int *)malloc(sizeof(int) * amount);
	ft_bzero((*stack)->vector, amount);
	(*stack)->size = 0;
}
