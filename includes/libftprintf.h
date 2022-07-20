/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:49:35 by jkiragu           #+#    #+#             */
/*   Updated: 2022/07/20 19:03:45 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
#define LIBPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include "../libft/libft.h"

# define HOLDER_CONVERSIONS "cspdiuxX%"
# define HOLDER_FLAGS "-0# +"
# define HOLDER_PREFIX "# +"
# define HOLDER_JUSTIFY_LEFT '-'
# define HOLDER_PADDING '0'
# define HOLDER_PRECISION '.'

# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

# define LC_HEX_PREFIX "0x"
# define UC_HEX_PREFIX "0X"

# define SPACE ' '
# define MINUS '-'
# define PLUS '+'

typedef struct s_fmt
{
	const char	*format;
	va_list		vargs;
	size_t		i;
	size_t		count;
}	t_fmt;

typedef struct s_placeholder
{
	char	*argument;
	char	*prefix;
	char	conversion;
	char	padding;
	int		justify_left;
	int		width;
	int		precision;
	size_t	counter;
}	t_placeholder;

// main functions
int				ft_printf(const char *format, ...);
int				ft_struct_printf(const char *format, va_list vargs);

// structure functions
t_fmt			*ft_init_format(const char *format , va_list vargs);
t_placeholder	*ft_init_placeholder(void);

// parsing functions
void			ft_placeholders(t_fmt *fmt);
void			*ft_parser(t_fmt *fmt, t_placeholder *holder);
void			ft_parse_flags(t_fmt *fmt, t_placeholder *holder);
void			ft_parse_width(t_fmt *fmt, t_placeholder *holder);
void			ft_parse_precision(t_fmt *fmt, t_placeholder *holder);

//utility functions
char			*ft_append_char(char const *s1, char const c);
char			*ft_strndup(const char *str, size_t n);
char			*pos_itoa(unsigned int num);
char			*hex_itoa(unsigned long long num, char *base);
char			*ft_uitoa_base(unsigned long long nbr, char *base);
void			strrev(char *str);

// conversion functions
void			ft_convert_by_type(t_fmt *fmt, t_placeholder *holder);
void			ft_print_char(t_fmt *fmt, t_placeholder *holder);
void			ft_print_digit(t_fmt *fmt, t_placeholder *holder);
void			ft_print_unsigned_digit(t_fmt *fmt, t_placeholder *holder);
void			ft_print_hex(t_fmt *fmt, t_placeholder *holder, char *base);
void			ft_print_pointer(t_fmt *fmt, t_placeholder *holder);
void			ft_print_str(t_fmt *fmt, t_placeholder *holder);
void			ft_print_percent(t_placeholder *holder);

// formatting functions
void			ft_pad_left(char **str, char padding, int width);
void			ft_pad_right(char **str, char padding, int width);
void			ft_add_prefix(t_placeholder *holder, int sign);
void			ft_hex_prefix(t_placeholder *holder);
void			ft_digit_width(t_placeholder *holder, int sign);

#endif
