# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 22:58:29 by qmebble           #+#    #+#              #
#    Updated: 2019/08/06 19:42:10 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	visualise.c \
		visualise_commands_pt1.c \
		visualise_commands_pt2.c \
		help_for_visualise_pt1.c \
		help_for_visualise_pt2.c \
		help_for_visualise_pt3.c

SRCS_PS =	../P_S/help_for_sort_pt1.c \
			../P_S/parsing.c \
			../P_S/help_for_parser.c \
			../P_S/make_new_stack.c \
			../P_S/rr_rrr_free_stack.c \
			../P_S/print_stack.c

INCLUDE = visualise.h
FLAGS = -Wall -Wextra -Werror
EXECUTABLE = visualisator
LIB = libft.a

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIB)
	@echo Compiling Visualisator...
	@gcc $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

$(LIB):
	@echo Compiling libft...
	@make -C ../libft/

new:
	@echo Recompiling Visualisator...
	@rm -rf ../$(EXECUTABLE)*
	@gcc $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..

debug:
	@echo Recompiling Visualisator...
	@rm -rf ../$(EXECUTABLE)*
	@gcc -g $(FLAGS) $(SRCS) $(SRCS_PS) ../libft.a -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ..
	@mv $(EXECUTABLE).* ..

clean:
	@rm -rf *.o
	@make -C ../libft clean

fclean: clean
	@rm -rf ../$(EXECUTABLE)*
	@make -C ../libft fclean
