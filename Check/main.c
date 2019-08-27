/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:16:18 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/04 19:10:29 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_functions.h"

void	checker_parsing(int argc, char **argv)
{
	int	i;
	int	temp;

	i = -1;
	if (argc == 2)
		second_situation(argv[1]);
	else
	{
		make_new_stack(&g_stack_a, argc - 1);
		while (++i < argc - 1)
		{
			temp = ft_atoi(argv[argc - i - 1]);
			if (!check_valid_number(argv[argc - i - 1], temp))
			{
				checker_error(0);
				return ;
			}
			g_stack_a->vector[i] = temp;
			g_stack_a->size++;
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	checker_parsing(argc, argv);
	sort_stack_manualy();
	return (0);
}
