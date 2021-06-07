NAME	= libftprintf.a
RM		= rm -rf
INCLUDES = -I./

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -c

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