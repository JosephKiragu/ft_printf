
NAME			= libftprintf.h
LIBFT_DIR		= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror 
INCS		= -I$(LIBFT_DIR) -I.
LFLAGS		= -L$(LIBFT_DIR) -lft 
LIB					= ar - rcs
LIB1		= ranlib

SRCS		= ft_convert_types.c ft_initialize.c ft_parser.c \
					ft_print_char.c ft_print_digit.c ft_print_hex.c \
					ft_print_percent.c ft_print_pointer.c ft_print_str.c \
					ft_print_unsigned_digit.c ft_printf.c ft_utility.c

OBJS		= $(SRCS:%.c = %.o)

all:			  $(NAME) 

$(NAME):		$(OBJS) $(LIBFT)
					ar rcs $(NAME) $(OBJS)
					$(LIB1) $(NAME)

.c.o:
			$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(LIBFT):	
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

bonus:		all

clean:		
			make clean -C $(LIBFT_DIR)
			rm -f $(OBJS)

fclean:		clean 
					make fclean -C(LIBFT_DIR)
					rm -f $(NAME)

re:					fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re


