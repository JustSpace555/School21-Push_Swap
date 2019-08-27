# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 19:16:01 by qmebble           #+#    #+#              #
#    Updated: 2019/08/06 19:41:28 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo Powered by; cat author
	@make -C ./Check/
	@make -C ./P_S/
	@make -C ./Visualise
	@make -C ./libft/

checker:
	@make -C ./Check

push_swap:
	@make -C ./P_S/

visualisator:
	@make -C ./Visualise/

new_checker:
	@make -C ./Check/ new

new_push_swap:
	@make -C ./P_S/ new

new_visualisator:
	@make -C ./Visualise/ new

new: new_push_swap new_checker new_visualisator

debug:
	@make -C ./Check/ debug
	@make -C ./P_S/ debug
	@make -C ./Visualise/ debug

clean:
	@make -C ./Check/ clean
	@make -C ./P_S/ clean
	@make -C ./libft/ clean
	@make -C ./Visualise/ clean

fclean:
	@rm -rf libft.a push_swap checker
	@make -C ./Check/ fclean
	@make -C ./P_S/ fclean
	@make -C ./libft/ fclean
	@make -C ./Visualise/ fclean

re: fclean all