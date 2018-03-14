/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 17:16:28 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 17:16:28 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void		ft_parse_flags(t_fields *fields, const char **format)
{
	int i;

	i = 0;
	while (ft_strchr(PRINTF_FLAGS, (*format)[i]))
	{
		if ((*format)[i] == '+')
			fields->plus = 1;
		else if ((*format)[i] == '-')
			fields->moins = 1;
		else if ((*format)[i] == ' ')
			fields->space = 1;
		else if ((*format)[i] == '0')
			fields->zero = 1;
		else if ((*format)[i] == '#')
			fields->diese = 1;
		i++;
	}
	*format += i;
}

void		ft_parse_precision(t_fields *fields, const char **format)
{
	int		i;
	char	*tmp;

	i = 0;
	if (**format == '.')
	{
		fields->point = 1;
		(*format)++;
		while (ft_strchr(PRINTF_NUMBERS, (*format)[i]))
			i++;
		if (i > 0)
		{
			ft_strncat(tmp = ft_strnew(i), *format, i);
			fields->precision = ft_atoi(tmp);
			free(tmp);
		}
	}
	*format += i;
}

void		ft_parse_size(t_fields *fields, const char **format)
{
	int i;

	i = 0;
	while (ft_strchr(PRINTF_SIZE, (*format)[i]))
	{
		if ((*format)[i] == 'h' && (*format)[i + 1] == 'h')
			fields->size = 'H';
		else if ((*format)[i] == 'h' && (*format)[i + 1] != 'h' &&
			(*format)[i - 1] != 'h' && fields->size == 0)
			fields->size = 'h';
		else if ((*format)[i] == 'l' && (*format)[i + 1] != 'l' &&
			(*format)[i - 1] != 'l')
			fields->size = 'l';
		else if ((*format)[i] == 'l' && (*format)[i + 1] == 'l')
			fields->size = 'L';
		else if ((*format)[i] == 'j')
			fields->size = 'j';
		else if ((*format)[i] == 'z')
			fields->size = 'z';
		i++;
	}
	*format += i;
}

void		ft_parse_correct(t_fields *fields, char type, const char *str)
{
	while (*str != type)
	{
		if (*str == '#')
			fields->diese = 1;
		if (*str == '+')
			fields->plus = 1;
		if (*str == '-')
			fields->moins = 1;
		str++;
	}
	if (fields->moins && fields->zero)
		fields->zero = 0;
	if (fields->space && fields->plus)
		fields->space = 0;
	if (fields->space && (fields->plus || ft_strchr("uUoO", fields->type)))
		fields->space = 0;
	if (fields->zero && fields->point && !ft_strchr("cCsS%", fields->type))
		fields->zero = 0;
	if (fields->type == 's' && ft_strchr("lL", fields->size))
		fields->type = 'S';
}

t_fields	ft_parse(const char **format)
{
	t_fields	fields;
	const char	*str;

	str = *format;
	fields = ft_fields_reset();
	ft_parse_flags(&fields, format);
	fields.width = ft_strnbr(*format);
	if (fields.width)
		(*format) += ft_lenint(fields.width);
	ft_parse_precision(&fields, format);
	ft_parse_size(&fields, format);
	while (!(ft_strchr(PRINTF_TYPE, **format)))
		(*format)++;
	fields.type = **format;
	ft_parse_correct(&fields, fields.type, str);
	(*format)++;
	return (fields);
}
