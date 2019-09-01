/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:23:32 by qmebble           #+#    #+#             */
/*   Updated: 2019/09/01 18:07:14 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualise.h"

int		checking_vis(char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		swap_vis(g_vis_stack_a);
	else if (ft_strcmp(command, "sb") == 0)
		swap_vis(g_vis_stack_b);
	else if (ft_strcmp(command, "ss") == 0)
		ss_vis();
	else if (ft_strcmp(command, "pa") == 0)
		push_vis(g_vis_stack_a, g_vis_stack_b);
	else if (ft_strcmp(command, "pb") == 0)
		push_vis(g_vis_stack_b, g_vis_stack_a);
	else if (ft_strcmp(command, "ra") == 0)
		rotate_vis(g_vis_stack_a);
	else if (ft_strcmp(command, "rb") == 0)
		rotate_vis(g_vis_stack_b);
	else if (ft_strcmp(command, "rr") == 0)
		rr_vis();
	else if (ft_strcmp(command, "rra") == 0)
		reverse_rotate_vis(g_vis_stack_a);
	else if (ft_strcmp(command, "rrb") == 0)
		reverse_rotate_vis(g_vis_stack_b);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr_vis();
	else
		return (0);
	return (1);
}

void	copy_elements_to_stack_b(void)
{
	int	i;

	if (!g_stack_b)
		return ;
	i = -1;
	while (++i < g_stack_a->size)
	{
		g_stack_b->vector[i] = g_stack_a->vector[i];
		g_stack_b->size++;
	}
}

int		pre_vis(int argc, char **argv)
{
	int *temp;
	int	k;

	parsing(argc, argv);
	make_new_stack(&g_stack_b, g_stack_a->size);
	copy_elements_to_stack_b();
	temp = (int *)malloc(sizeof(int) * g_stack_b->size);
	copy_elements_to_temp_array(&temp, g_stack_b->size);
	quicksort(0, ARRAY_SIZE(g_stack_a));
	make_indexes(&g_stack_a, &g_stack_b);
	g_vis_stack_a = make_new_vis_stack();
	g_vis_stack_b = make_new_vis_stack();
	make_new_vis_stack_array(g_vis_stack_a, g_stack_a->size);
	make_new_vis_stack_array(g_vis_stack_b, g_stack_a->size);
	k = 1;
	while (50 * k < find_max_index(g_vis_stack_a))
		k++;
	make_vis_stack_a(temp);
	free(temp);
	return (k);
}

int		main(int argc, char **argv)
{
	char	*command;
	int		k;
	int		gnl_ret;

	k = pre_vis(argc, argv);
	print_vis_array(g_vis_stack_a);
	while ((gnl_ret = get_next_line(0, &command)))
	{
		if (!checking_vis(command))
		{
			ft_printf("Error\n");
			free(command);
			free_all();
			exit(-1);
		}
		system("clear");
		write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 20);
		print_vis_stacks(k, command);
		system("sleep 0.1");
		free(command);
	}
	system("clear");
	print_vis_stacks(k, "Finish");
	system("sleep 3");
	free_all();
}
