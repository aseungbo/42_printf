NAME	= libftprintf.a
RM		= rm -rf
INCLUDES = -I./

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -c

# SRC, OBJS
SRCS	= ft_printf.c \
			ft_print_char.c \
			ft_print_string.c \
			ft_spec.c \
			ft_width.c \
			ft_putchar.c \
			ft_isdigit.c \
			ft_print_int.c \
			itoa.c \


SURPL_O = ft_print_char.o \
			ft_print_string.o \
			ft_spec.o \
			ft_width.o \
			ft_putchar.o \
			ft_isdigit.o \
			ft_print_int.o \
			itoa.o \


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