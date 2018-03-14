/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 12:51:19 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 12:51:19 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

t_prints	ft_convert(intmax_t *data, t_fields *fields)
{
	t_prints print;

	print = ft_print_reset();
	print.data = (void *)*data;
	if (ft_strchr("sS", fields->type))
		print = ft_cvt_s(&print, fields);
	else if (ft_strchr("cC%", fields->type))
		print = ft_cvt_c(&print, fields);
	else if (ft_strchr("dDiuU", fields->type))
		print = ft_cvt_diu(&print, fields);
	else if (ft_strchr("xXp", fields->type))
		print = ft_cvt_xp(&print, fields);
	else if (ft_strchr("oO", fields->type))
		print = ft_cvt_o(&print, fields);
	return (print);
}
