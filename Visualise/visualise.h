/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:22:37 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/06 19:11:31 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISE_H
# define VISUALISE_H

# include "../P_S/push_swap_functions.h"
# include "../Check/checker_functions.h"

# define ARRAY_VIS_SIZE(stack)	stack->size - 1
# define TOP_VIS_ELEM(stack)	stack->array[ARRAY_VIS_SIZE(stack)]
# define VIS_ELEM(stack, i)		stack->array[i]

typedef struct					s_vis_element
{
	int							data;
	int							index;
	int							if_changing;
	int							for_what_changing;
}								t_vis_element;

typedef struct					s_vis_array
{
	t_vis_element				*array;
	int							size;
}								t_vis_array;

t_vis_array						*g_vis_stack_a;
t_vis_array						*g_vis_stack_b;

/*
**								Visualise functions
*/
void							swap_vis(t_vis_array *stack);
void							ss_vis();
void							push_vis(t_vis_array *dest, t_vis_array *src);
void							reverse_rotate_vis(t_vis_array *stack);
void							rrr_vis(void);
void							rotate_vis(t_vis_array *stack);
void							rr_vis(void);

/*
**								Visualisator help functions
*/
int								find_max_data(t_vis_array *stack);
int								find_min_data(t_vis_array *stack);
int								find_max_index(t_vis_array *stack);
int								find_min_index(t_vis_array *stack);
void							print_vis_stacks(int k, char *command);
void							make_new_vis_stack_array(t_vis_array *stack,
															int size);
int								find_max_data_in_temp_array(int *temp,
															int size);
t_vis_array						*make_new_vis_stack(void);
void							make_new_vis_stack_array(t_vis_array *stack,
															int size);
void							make_vis_stack_a(int *temp);
void							copy_elements_to_stack_b(void);
int								checking_vis(char *command);
void							print_vis_array(t_vis_array *stack);
void							copy_elements_to_temp_array(int **temp,
															int size);
void							free_all(void);
int								pre_vis(int argc, char **argv);

#endif
