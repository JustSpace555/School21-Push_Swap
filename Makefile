# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: space <space@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 19:16:01 by qmebble           #+#    #+#              #
#    Updated: 2019/10/20 20:03:07 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo Powered by; cat author
	@make -C ./libft/
	@make -C ./Check/
	@make -C ./P_S/
	@make -C ./Vizualize

checker:
	@make -C ./Check

push_swap:
	@make -C ./P_S/

vizualizator:
	@make -C ./Vizualize/

new_checker:
	@make -C ./Check/ new

new_push_swap:
	@make -C ./P_S/ new

new_vizualizator:
	@make -C ./Vizualize/ new

new: new_push_swap new_checker new_vizualizator

debug:
	@make -C ./Check/ debug
	@make -C ./P_S/ debug
	@make -C ./Vizualize/ debug

clean:
	@make -C ./Check/ clean
	@make -C ./P_S/ clean
	@make -C ./libft/ clean
	@make -C ./Vizualize/ clean

fclean:
	@rm -rf push_swap checker
	@make -C ./Check/ fclean
	@make -C ./P_S/ fclean
	@make -C ./libft/ fclean
	@make -C ./Vizualize/ fclean

re: fclean all
