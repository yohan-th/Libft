/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 18:08:46 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 18:12:46 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"

# define PRINTF_TYPE "sSpdDioOuUxXcC%"
# define PRINTF_ALL_FIELDS "#0-+ *123456789.hljz"
# define PRINTF_FLAGS "-+0 #"
# define PRINTF_SIZE "hljz"
# define PRINTF_NUMBERS "0123456789"

typedef struct	pfs_fields
{
	BOOL	diese;
	BOOL	zero;
	BOOL	moins;
	BOOL	plus;
	BOOL	space;
	BOOL	point;
	BOOL	size;
	int		width;
	int		precision;
	char	type;
}				pf_fields;

typedef struct	pfs_prints
{
	void		*data;
	int			space_bfr;
	int			space_aftr;
	int			zero_bfr;
	int			zero_aftr;
	int			plus;
	int			moins;
	int			space;
	int			zero_x;
	int			zero_x_up;
	int			free;
}				pf_print;

int				ft_printf(const char *format, ...);
pf_fields		pf_fields_reset(void);
pf_fields		pf_parse(const char **format);
intmax_t		pf_type(va_list ap, pf_fields *fields);
pf_print		pf_convert(intmax_t *data, pf_fields *fields);
int				pf_print_field(pf_print *data_prt, pf_fields *fields);
pf_print		pf_print_reset(void);
void			pf_parse_flags(pf_fields *fields, const char **format);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               Convert by type                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

pf_print		pf_cvt_s(pf_print *data_prt, pf_fields *fields);
pf_print		pf_cvt_c(pf_print *data_prt, pf_fields *fields);
pf_print		pf_cvt_diu(pf_print *print, pf_fields *fields);
pf_print		pf_cvt_xp(pf_print *data_prt, pf_fields *fields);
pf_print		pf_cvt_o(pf_print *data_prt, pf_fields *fields);

#endif
