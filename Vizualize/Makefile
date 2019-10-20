# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 22:58:29 by qmebble           #+#    #+#              #
#    Updated: 2019/10/20 20:06:13 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	vizualize.c \
		vizualize_commands_pt1.c \
		vizualize_commands_pt2.c \
		help_for_vizualize_pt1.c \
		help_for_vizualize_pt2.c \
		help_for_vizualize_pt3.c

SRCS_PS =	../P_S/help_for_sort_pt1.c \
			../P_S/parsing.c \
			../P_S/help_for_parser.c \
			../P_S/make_new_stack.c \
			../P_S/rr_rrr_free_stack.c \
			../P_S/print_stack.c

INCLUDE = vizualize.h
FLAGS = -Wall -Wextra -Werror
EXECUTABLE = vizualizator

all: $(EXECUTABLE)

$(EXECUTABLE):
	@echo Compiling Vizualizator...
	@gcc $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

new: fclean
	@echo Recompiling Vizualizator...
	@gcc $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

debug: fclean
	@echo Recompiling Vizualizator...
	@gcc -g $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..
	@mv $(EXECUTABLE).* ..

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ../$(EXECUTABLE)*
