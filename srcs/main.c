# include <stdio.h>

# include "../includes/libftprintf.h"

# include "ft_printf.c"
# include "ft_initialize.c"
# include "ft_parser.c"
# include "ft_convert_types.c"
# include "ft_print_digit.c"
# include "ft_print_unsigned_digit.c"
# include "ft_print_char.c"
# include "ft_print_str.c"
# include "ft_print_hex.c"
# include "ft_print_pointer.c"
# include "ft_print_percent.c"
# include "ft_utility.c"
# include "../libft/libft.h"
# include "../libft/ft_isprint.c"
# include "../libft/ft_isdigit.c"
# include "../libft/ft_memset.c"
# include "../libft/ft_strchr.c"
# include "../libft/ft_strdup.c"
# include "../libft/ft_strlen.c"
# include "../libft/ft_memcpy.c"
# include "../libft/ft_strlcat.c"
# include "../libft/ft_strlcpy.c"
# include "../libft/ft_itoa.c"
# include "../libft/ft_calloc.c"
# include "../libft/ft_bzero.c"
# include "../libft/ft_strjoin.c"


int main (void)
{
	// char *null_str = NULL;
	// char x = 'c';
	// ptr = &x;

	// // //ft_printf("This is character %--c\n", 'x');
	int z;
	// int y;

	// // // x = ft_printf("This is character %.2s\n", "Hello");

// // y = printf("This is character %.2s\n", "Hello");

	// printf("original function = %d\n", z);
	// printf("my function = %d\n", y);

	// ft_printf("%.3d\n", -100);
	// printf("%.3d\n", -1);

	//  ft_printf("mine: %.0u\n", 2);
	//  printf("original: %.0u\n", 2);

	// ft_printf("my function : %01.0u\n", 0);
	// printf(" Original function : %01.0u\n", 0);

	z = ft_printf("%");

	printf("\nvalue of z = %i\n", z);
}