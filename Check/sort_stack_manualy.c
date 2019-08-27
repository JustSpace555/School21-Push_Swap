/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_manualy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:16:20 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 20:04:17 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_functions.h"

void	sort_stack_manualy(void)
{
	int	i;

	check_commands();
	i = 0;
	while (++i < g_stack_a->size)
		if (g_stack_a->vector[i - 1] < g_stack_a->vector[i])
			checker_error(1);
	write(1, "OK\n", 3);
	free_stack(&g_stack_a);
	return ;
}
