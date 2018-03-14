/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 14:38:10 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:38:10 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

intmax_t	ft_type_str(va_list ap, char type)
{
	intmax_t data;

	if (type == 's')
		data = (intmax_t)va_arg(ap, char*);
	else if (type == 'S')
		data = (intmax_t)va_arg(ap, wchar_t*);
	else
		return (0);
	return (data);
}

intmax_t	ft_type_char(va_list ap, char type)
{
	intmax_t data;

	if (type == 'C')
		data = (intmax_t)va_arg(ap, wchar_t);
	else if (type == 'c')
		data = (intmax_t)va_arg(ap, int);
	else if (type == '%')
		data = '%';
	else
		return (0);
	return (data);
}

intmax_t	ft_type_int(va_list ap, char type)
{
	intmax_t data;

	if (ft_strchr("oOuUxX", type))
		data = (intmax_t)va_arg(ap, uintmax_t);
	else if (ft_strchr("dDi", type))
		data = (intmax_t)va_arg(ap, intmax_t);
	else if (type == 'p')
		data = (intmax_t)va_arg(ap, void *);
	else
		return (0);
	return (data);
}

intmax_t	ft_type(va_list ap, t_fields *fields)
{
	intmax_t data;

	if (ft_strchr("cC%", fields->type))
		data = ft_type_char(ap, fields->type);
	else if (ft_strchr("sS", fields->type))
		data = ft_type_str(ap, fields->type);
	else if (ft_strchr("dDioOuUxXp", fields->type))
		data = ft_type_int(ap, fields->type);
	else
		return (0);
	return (data);
}
