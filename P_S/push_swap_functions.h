/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:15:42 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/29 17:38:49 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNCTIONS_H
# define PUSH_SWAP_FUNCTIONS_H

# include "../libft/Headers/libft.h"

typedef struct	s_vector
{
	int			*vector;
	int			size;
}				t_vector;

# define ARRAY_SIZE(stack) (stack)->size - 1
# define TOP_ELEM(stack) (stack)->vector[ARRAY_SIZE(stack)]
# define ELEM(stack, i) (stack)->vector[i]

t_vector		*g_stack_a;
t_vector		*g_stack_b;

/*
**				Global important functions
*/

void			make_new_stack(t_vector **stack, int amount);
void			free_stack(t_vector **stack);

/*
**				Push_swap_functions
*/

void			swap(t_vector *stack, char *str);
void			ss(char *str);
void			push(t_vector *dest, t_vector *src, char *str);
void			rotate(t_vector *stack, char *str);
void			rr(char *str);
void			reverse_rotate(t_vector *stack, char *str);
void			rrr(char *str);

/*
**				Sort algorithm
*/

int				find_lasts_elements(t_vector *stack, int limit);
void			make_indexes(t_vector **stack_a, t_vector **stack_b);
void			quicksort(int left, int right);
int				find_average(t_vector *stack);
int				find_average_limit(t_vector *stack, int limit);
int				ft_find_max(t_vector *stack);
int				ft_find_min(t_vector *stack);
void			split_to_b(int size);
void			max_in_b_to_a(void);
void			split_to_a(int size);
void			ft_push_swap(void);
void			sort_without_split(int max);
void			sort_with_split(int max);
void			sort_in_progress(void);
void			sort(void);

/*
**				Parser
*/

void			parsing(int amount, char **array);
void			second_situation(char *numbers_str);
int				is_sorted(t_vector *stack);
int				check_for_numbers(char *str);
int				check_for_dublicate(int	num);
int				check_valid_number(char *num_str, int num);
int				count_amount_of_elements(char *numbers_str);
void			free_str_array(char ***str, int amount);

/*
**				Sort_simple
*/

void			rotate_min(t_vector *stack);
void			five_situation(void);
void			sort_a(void);
void			sort_b(void);
void			sort_simple(void);

/*
**				For debug
*/

void			print_stack(t_vector *stack, char stack_letter);

#endif
