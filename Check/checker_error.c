/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:16:12 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 19:16:13 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_functions.h"

void	checker_error(int flag)
{
	free_stack(&g_stack_a);
	free_stack(&g_stack_b);
	if (flag == 0)
		write(1, "Error\n", 6);
	else if (flag == 1)
		write(1, "KO\n", 3);
	exit(-1);
}
