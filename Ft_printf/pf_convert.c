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

pf_print	pf_convert(intmax_t *data, pf_fields *fields)
{
	pf_print print;

	print = pf_print_reset();
	print.data = (void *)*data;
	if (ft_strchr("sS", fields->type))
		print = pf_cvt_s(&print, fields);
	else if (ft_strchr("cC%", fields->type))
		print = pf_cvt_c(&print, fields);
	else if (ft_strchr("dDiuU", fields->type))
		print = pf_cvt_diu(&print, fields);
	else if (ft_strchr("xXp", fields->type))
		print = pf_cvt_xp(&print, fields);
	else if (ft_strchr("oO", fields->type))
		print = pf_cvt_o(&print, fields);
	return (print);
}
