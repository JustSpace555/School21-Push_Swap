/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:35:40 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 21:37:31 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_functions.h"

int		check_for_dublicate(int num)
{
	int	i;

	i = 0;
	while (i < g_stack_a->size)
	{
		if (ELEM(g_stack_a, i) == num)
			return (1);
		i++;
	}
	return (0);
}

int		check_for_digits(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '\0')
		if (!ft_isdigit(str[i]))
		{
			if ((str[i] == '-' || str[i] == '+') && i == 0)
				continue;
			else
				return (0);
		}
	return (1);
}

int		count_amount_of_elements(char *numbers_str)
{
	int	amount_elem;
	int	i;

	i = -1;
	amount_elem = 0;
	while (numbers_str[++i] && numbers_str[i] != '\0')
		if (numbers_str[i] == ' ' && (numbers_str[i + 1] == '-' ||
			numbers_str[i + 1] == '+' || ft_isdigit(numbers_str[i + 1])))
			amount_elem++;
	if (amount_elem == 0 && !numbers_str[0])
		exit(-1);
	return (amount_elem + 1);
}

void	free_str_array(char ***str, int amount)
{
	int	i;

	i = -1;
	while (++i <= amount)
		free((*str)[i]);
	free(*str);
}

int		check_valid_number(char *num_str, int num)
{
	if ((num == 0 && num_str[0] != '0' && num_str[1] != '0') ||
		!check_for_digits(num_str) || check_for_dublicate(num))
		return (0);
	return (1);
}
