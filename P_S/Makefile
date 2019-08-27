# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 19:15:31 by qmebble           #+#    #+#              #
#    Updated: 2019/08/06 19:42:05 by qmebble          ###   ########.fr        #
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
LIB = libft.a

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIB)
	@echo Compiling Push_Swap...
	@gcc $(FLAGS) $(SRCS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..


$(LIB):
	@echo Compiling libft...
	@make -C ../libft/

new:
	@echo Recompiling Push_Swap...
	@rm -rf ../$(EXECUTABLE)*
	@gcc $(FLAGS) $(SRCS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

debug:
	@echo Recompiling Push_Swap...
	@rm -rf ../$(EXECUTABLE)*
	@gcc -g $(FLAGS) $(SRCS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..
	@mv $(EXECUTABLE).* ..

clean:
	@rm -rf *.o
	@make -C ../libft clean

fclean: clean
	@rm -rf ../$(EXECUTABLE)*
	@make -C ../libft fclean

re: fclean all
