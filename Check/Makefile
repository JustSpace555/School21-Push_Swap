# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: space <space@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 19:16:23 by qmebble           #+#    #+#              #
#    Updated: 2019/09/01 17:07:23 by space            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	check_commands.c\
		checker_error.c\
		main.c\
		sort_stack_manualy.c

SRCS_PS = ../P_S/make_new_stack.c\
		../P_S/print_stack.c \
		../P_S/rr_rrr_free_stack.c \
		../P_S/swap_ss_push_stack.c\
		../P_S/parsing.c \
		../P_S/is_sorted.c \
		../P_S/help_for_parser.c

INCLUDE = checker_functions.h
EXECUTABLE = checker
FLAGS = -Wall -Wextra -Werror
LIB = libft.a

all:
	@echo Compiling Checker...
	@gcc $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -I $(INCLUDE) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

new: fclean
	@echo Recompiling Checker...
	@gcc $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -I $(INCLUDE) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

debug: fclean
	@echo Recompiling Checker...
	@gcc -g $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -I $(INCLUDE) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..
	@mv $(EXECUTABLE).* ..

clean:
	@rm -rf *.o

fclean:
	@rm -rf ../$(EXECUTABLE)*

re: fclean all
