/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_visualise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:25:48 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/06 16:20:25 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualise.h"

int		find_max_data(t_vis_array *stack)
{
	int	i;
	int	max;

	i = -1;
	max = -MAX_INT - 1;
	while (++i < stack->size)
		if (max < stack->array[i].data)
			max = stack->array[i].data;
	return (max);
}

int		find_max_data_in_temp_array(int *temp, int size)
{
	int	i;
	int	max;

	i = -1;
	max = -MAX_INT - 1;
	while (++i < size)
		if (max < temp[i])
			max = temp[i];
	return (max);
}

int		find_max_index(t_vis_array *stack)
{
	int	i;
	int	max_i;

	max_i = 0;
	i = -1;
	while (++i < stack->size)
		if (max_i < stack->array[i].index)
			max_i = stack->array[i].index;
	return (max_i);
}

int		find_min_data(t_vis_array *stack)
{
	int	i;
	int	min;

	i = -1;
	min = MAX_INT;
	while (++i < stack->size)
		if (min > stack->array[i].data)
			min = stack->array[i].data;
	return (min);
}

int		find_min_index(t_vis_array *stack)
{
	int	i;
	int	min_i;

	min_i = MAX_INT;
	i = -1;
	while (++i < stack->size)
		if (min_i > stack->array[i].index)
			min_i = stack->array[i].index;
	return (min_i);
}
