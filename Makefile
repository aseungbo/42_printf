# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 18:29:48 by seuan             #+#    #+#              #
#    Updated: 2021/06/12 18:34:48 by seuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
RM		= rm -rf
INCLUDES = -I./

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -c

# SRC, OBJS
SRCS	= ft_printf.c \
			ft_print_char.c \
			ft_print_string.c \
			ft_print_u.c \
			ft_print_base.c \
			ft_print_pointer.c \
			ft_print_percent.c \
			ft_print_int.c \
			ft_spec.c \
			ft_width.c \
			ft_base.c \
			pf_itoa.c \
			u_itoa.c \
			ft_utils.c \
			ft_flags.c \

SRC_O	= ft_printf.o \
			ft_print_char.o \
			ft_print_string.o \
			ft_print_u.o \
			ft_print_base.o \
			ft_print_pointer.o \
			ft_print_percent.o \
			ft_print_int.o \
			ft_spec.o \
			ft_width.o \
			ft_base.o \
			pf_itoa.o \
			u_itoa.o \
			ft_utils.o \
			ft_flags.o \

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
		$(RM) $(SRC_O)

fclean : clean
		make fclean -C ./libft
		$(RM) $(NAME)

re : fclean clean all

.PHONY:			all clean fclean re