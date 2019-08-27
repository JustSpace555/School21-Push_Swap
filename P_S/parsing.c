/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:34 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:46:38 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

void	second_situation(char *numbers_str)
{
	int		i;
	int		j;
	int		amount_elements;
	char	**numbers_arr;

	i = -1;
	amount_elements = count_amount_of_elements(numbers_str);
	make_new_stack(&g_stack_a, amount_elements);
	numbers_arr = ft_strsplit(numbers_str, ' ');
	while (++i < amount_elements)
	{
		j = ft_atoi(numbers_arr[amount_elements - i - 1]);
		if (!check_valid_number(numbers_arr[amount_elements - i - 1], j))
		{
			free_stack(&g_stack_a);
			free_str_array(&numbers_arr, amount_elements);
			write(1, "Error\n", 6);
			exit(-1);
		}
		g_stack_a->vector[g_stack_a->size++] = j;
	}
	free_str_array(&numbers_arr, amount_elements);
}

void	parsing(int amount, char **array)
{
	int	temp;

	if (amount == 2)
		second_situation(array[1]);
	else
	{
		make_new_stack(&g_stack_a, amount - 1);
		while (amount > 1)
		{
			temp = ft_atoi(array[amount - 1]);
			if (!check_valid_number(array[amount - 1], temp))
			{
				free_stack(&g_stack_a);
				write(1, "Error\n", 6);
				exit(-1);
			}
			g_stack_a->vector[g_stack_a->size++] = temp;
			amount--;
		}
	}
	if (g_stack_a->size == 1)
	{
		free_stack(&g_stack_a);
		exit(-1);
	}
}
