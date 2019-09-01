# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: space <space@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 19:15:31 by qmebble           #+#    #+#              #
#    Updated: 2019/09/01 17:07:57 by space            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		make_new_stack.c \
		parsing.c \
		print_stack.c \
		rr_rrr_free_stack.c \
		sort.c \
		swap_ss_push_stack.c \
		is_sorted.c \
		sort_simple.c \
		help_for_parser.c \
		help_for_sort_pt1.c \
		help_for_sort_pt2.c

INCLUDE = push_swap_funstions.h
FLAGS = -Wall -Wextra -Werror
EXECUTABLE = push_swap

all: $(EXECUTABLE)

$(EXECUTABLE):
	@echo Compiling Push_Swap...
	@gcc $(FLAGS) $(SRCS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

new: fclean
	@echo Recompiling Push_Swap...
	@gcc $(FLAGS) $(SRCS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

debug: fclean
	@echo Recompiling Push_Swap...
	@gcc -g $(FLAGS) $(SRCS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..
	@mv $(EXECUTABLE).* ..

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ../$(EXECUTABLE)*

re: fclean all
