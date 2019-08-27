/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:25 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:46:24 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	parsing(argc, argv);
	if (!g_stack_a)
		return (0);
	if (g_stack_a->size <= 5)
		sort_simple();
	else
		sort();
	free_stack(&g_stack_a);
	free_stack(&g_stack_b);
	return (0);
}
