# include "../includes/libftprintf.h"



void ft_parse_flags(t_fmt *fmt, t_placeholder *holder)
{
	char	*tmp;

	if (!holder->prefix)
			holder->prefix = ft_strdup(""); //ft_strdup because holder prefix can be combined
	while (ft_strchr(HOLDER_FLAGS, fmt->format[fmt->i]))
		{
			if (fmt->format[fmt->i] == HOLDER_JUSTIFY_LEFT)
					holder->justify_left = 1;
			if (ft_strchr(HOLDER_PREFIX, fmt->format[fmt->i]))
				{
					tmp = holder->prefix;
					holder->prefix = ft_append_char(tmp, fmt->format[fmt->i]); 
					free(tmp);
				}
			if (fmt->format[fmt->i] == HOLDER_PADDING)
					holder->padding = HOLDER_PADDING;
			fmt->i++;
		}
}

void ft_parse_width(t_fmt *fmt, t_placeholder *holder)
{
	int width;

	width = holder->width;
	if (ft_isdigit(fmt->format[fmt->i]))
		{
			while (ft_isdigit(fmt->format[fmt->i]))
			{
				width = (width * 10) + (fmt->format[fmt->i] - '0');
				fmt->i++;
			}
		}
	holder->width = width;
}


void ft_parse_precision(t_fmt *fmt, t_placeholder *holder)
{
	int precision;

	precision = holder->precision;

	if (fmt->format[fmt->i] == HOLDER_PRECISION)
	{
		fmt->i++; // try reformat this code
		if (!ft_isdigit(fmt->format[fmt->i]))
			precision = 0;
		if (ft_isdigit(fmt->format[fmt->i]))
		{
			precision = 0;
			while (ft_isdigit(fmt->format[fmt->i]))
			{
				precision = (precision * 10) + (fmt->format[fmt->i] - '0');
				fmt->i++;
			}
		}
	}
	holder->precision = precision;
}

void ft_parse_conversion(t_fmt *fmt, t_placeholder *holder)
{
	if (!ft_strchr(HOLDER_FLAGS, fmt->format[fmt->i]) && ft_isprint(fmt->format[fmt->i]))
	{
			holder->conversion = fmt->format[fmt->i];
			fmt->i++; // take pointer to the next value this is done by all functions in this folder
	}
}

void	*ft_parser(t_fmt *fmt, t_placeholder *holder)//returning a void pointer since the object to be is of type defined.
{
	ft_parse_flags(fmt, holder);
	ft_parse_width(fmt, holder);
	ft_parse_precision(fmt, holder);
	ft_parse_conversion(fmt, holder);
	if (!holder->conversion && ft_strchr(HOLDER_FLAGS, fmt->format[fmt->i]))
			ft_parser(fmt, holder); // incase there are a combination of flags
	return (holder);
}