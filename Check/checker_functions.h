/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:16:15 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/03 22:05:42 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_FUNCTIONS_H
# define CHECKER_FUNCTIONS_H

# include "../P_S/push_swap_functions.h"

/*
**		Checker functions
*/

void	checker_parsing(int argc, char **argv);
void	checker_error(int flag);
void	check_commands(void);
int		checking(char *command);
void	sort_stack_manualy(void);

#endif
