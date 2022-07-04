# include "libftprintf.h"

void	ft_print_char(t_fmt *fmt, t_placeholder *holder)
{
	char	value;
	value = va_arg(fmt->vargs, int);

	if (!holder->width)
			holder->width += 1;
	holder->argument = (char *)malloc(sizeof(char) * holder->width); // because function memset expects a char pointer
	if (!holder->argument)
			return;
	ft_memset(holder->argument, SPACE, holder->width);
	if (holder->justify_left == 1) //justify left can only be one
		holder->argument[0] = value;
	else 
		holder->argument[holder->width - 1] = value;
	holder->counter = holder->width;
}