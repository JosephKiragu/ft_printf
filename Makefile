

NAME		= libftprintf.a

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCS_DIR	= ./includes

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCS		= -I$(INCS_DIR) -I$(LIBFT_DIR)
LFLAGS		= -L$(LIBFT_DIR) -lft
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

SRC_DIR		= ./srcs


SRCS		= $(SRC_DIR)/ft_convert_types.c \
			$(SRC_DIR)/ft_initialize.c \
			$(SRC_DIR)/ft_parser.c \
			$(SRC_DIR)/ft_print_char.c \
			$(SRC_DIR)/ft_print_digit.c \
			$(SRC_DIR)/ft_print_hex.c \
			$(SRC_DIR)/ft_print_percent.c \
			$(SRC_DIR)/ft_print_pointer.c \
			$(SRC_DIR)/ft_print_str.c \
			$(SRC_DIR)/ft_print_unsigned_digit.c \
			$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_utility.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o: 		
			$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)
			echo "libft/libft.a"

bonus:		all

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re