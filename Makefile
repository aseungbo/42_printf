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
			ft_print_int.c \
			ft_spec.c \
			ft_width.c \
			ft_base.c \
			pf_putchar.c \
			pf_isdigit.c \
			pf_itoa.c \
			u_itoa.c \

SURPL_O = ft_print_char.o \
			ft_print_string.o \
			ft_print_u.o \
			ft_print_base.o \
			ft_print_pointer.o \
			ft_print_int.o \
			ft_spec.o \
			ft_width.o \
			ft_base.o \
			pf_putchar.o \
			pf_isdigit.o \
			pf_itoa.o \
			u_itoa.o \


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