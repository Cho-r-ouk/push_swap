# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:40:31 by cmasnaou          #+#    #+#              #
#    Updated: 2024/01/31 09:38:57 by cmasnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	push_swap
BONUS	=	checker
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror
HEADM	=	Mandatory/push_swap.h
HEADB	=	Bonus/push_swap_bonus.h
SRCM	=	Mandatory/ft_split.c Mandatory/libft.c\
			Mandatory/moves.c Mandatory/parse.c\
			Mandatory/sort.c Mandatory/push_swap_utils.c\
			Mandatory/push_swap.c
SRCB	=	Bonus/ft_split_bonus.c Bonus/libft_bonus.c\
			Bonus/moves_bonus.c Bonus/get_next_line_bonus.c\
			Bonus/get_next_line_utils_bonus.c\
			Bonus/parse_bonus.c Bonus/checker.c
OBJM	=	$(SRCM:.c=.o)
OBJB	=	$(SRCB:.c=.o)

MAGENTA	=	\033[0;35m
CYAN	=	\033[1;92m
YELLOW	=	\033[1;33m
NC		=	\033[0m

all:	$(NAME)
$(NAME):$(OBJM)
		@$(CC) $(OBJM) -o $(NAME)
		@echo "🌸 ${CYAN}Done! 🌸 ${NC}use ${MAGENTA}./push_swap 🌸"
%.o:%.c $(HEADM)
		@$(CC) $(CFLAGS) -c $< -o $@
bonus:	$(BONUS)
$(BONUS):$(OBJB)
		@$(CC) $(OBJB) -o $(BONUS)
		@echo "🌸 ${CYAN}Done! 🌸 ${NC}use ${MAGENTA}./checker 🌸"
%.o:%.c $(HEADB)
		@$(CC) $(CFLAGS) -c $< -o $@
clean:
		@$(RM) $(OBJM) $(OBJB)
		@echo "🌸 ${YELLOW}Cleanup done! 🌸"
fclean: clean
		@$(RM) $(NAME) $(BONUS)
re:		fclean all
.PHONY:	clean