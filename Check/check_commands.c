/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:16:10 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/04 19:08:46 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_functions.h"

int		checking(char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		swap(g_stack_a, NULL);
	else if (ft_strcmp(command, "sb") == 0)
		swap(g_stack_b, NULL);
	else if (ft_strcmp(command, "ss") == 0)
		ss(NULL);
	else if (ft_strcmp(command, "pa") == 0)
		push(g_stack_a, g_stack_b, NULL);
	else if (ft_strcmp(command, "pb") == 0)
		push(g_stack_b, g_stack_a, NULL);
	else if (ft_strcmp(command, "ra") == 0)
		rotate(g_stack_a, NULL);
	else if (ft_strcmp(command, "rb") == 0)
		rotate(g_stack_b, NULL);
	else if (ft_strcmp(command, "rr") == 0)
		rr(NULL);
	else if (ft_strcmp(command, "rra") == 0)
		reverse_rotate(g_stack_a, NULL);
	else if (ft_strcmp(command, "rrb") == 0)
		reverse_rotate(g_stack_b, NULL);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(NULL);
	else
		return (0);
	return (1);
}

void	check_commands(void)
{
	char		*command;

	make_new_stack(&g_stack_b, g_stack_a->size);
	while (get_next_line(0, &command))
	{
		if (!checking(command))
		{
			free(command);
			checker_error(0);
		}
		free(command);
	}
	if (g_stack_b && g_stack_b->size > 0)
		checker_error(1);
}
