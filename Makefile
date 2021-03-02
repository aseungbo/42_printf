# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 15:00:45 by seuan             #+#    #+#              #
#    Updated: 2021/03/02 16:27:55 by seuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
RM		= rm -rf
INCLUDES = -I./includes

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

# SRC, OBJS
SRCS	= ft_printf.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
		make -C ./libft
		cp ./libft/libft.a $(NAME)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar -rc $(NAME) $(OBJS)

all : $(NAME)

clean :
		make clean -C ./libft
		$(RM) $(OBJS)
	
fclean :
		make fclean -C ./libft
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus