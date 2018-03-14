/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 18:06:23 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 18:06:27 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int		ft_undef_char(const char **format)
{
	t_fields	fields;
	intmax_t	data;
	t_prints	print;
	int			len_print;

	(*format)++;
	fields = ft_fields_reset();
	ft_parse_flags(&fields, format);
	fields.width = ft_strnbr(*format);
	if (fields.width)
		(*format) += ft_lenint(fields.width);
	while (ft_strchr(PRINTF_ALL_FIELDS, **format))
	{
		if (**format == '-')
			fields.moins = 1;
		(*format)++;
	}
	data = (intmax_t)**format;
	(*format)++;
	fields.type = 'c';
	print = ft_convert(&data, &fields);
	len_print = ft_print_field(&print, &fields);
	return (len_print);
}

int		ft_undef_beha(const char **format)
{
	int	i;

	if (ft_strlen(*format) == 1)
	{
		*format += 1;
		return (1);
	}
	i = 1;
	while (ft_strchr(PRINTF_ALL_FIELDS, (*format)[i]))
		i++;
	if ((!ft_strchr(PRINTF_TYPE, (*format)[i]) &&
		ft_strchr(PRINTF_ALL_FIELDS, (*format)[i])) ||
		(*format)[i] == '\0')
	{
		*format += i;
		return (1);
	}
	else if (!ft_strchr(PRINTF_TYPE, (*format)[i]) &&
		!ft_strchr(PRINTF_ALL_FIELDS, (*format)[i]))
		return (-1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fields	fields;
	intmax_t	data;
	t_prints	print;
	int			len_print;

	va_start(ap, format);
	len_print = 0;
	while (*format)
	{
		if (*format == '%' && ft_undef_beha(&format) == 0)
		{
			format++;
			fields = ft_parse(&format);
			data = ft_type(ap, &fields);
			print = ft_convert(&data, &fields);
			len_print += ft_print_field(&print, &fields);
		}
		else if (*format == '%' && ft_undef_beha(&format) == -1)
			len_print += ft_undef_char(&format);
		else if (ft_strlen(format) >= 1)
			len_print += ft_putchar(*format++);
	}
	va_end(ap);
	return (len_print);
}
