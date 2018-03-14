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

typedef struct	s_fields
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
}				t_fields;

typedef struct	s_prints
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
}				t_prints;

int				ft_printf(const char *format, ...);
t_fields		ft_fields_reset(void);
t_fields		ft_parse(const char **format);
intmax_t		ft_type(va_list ap, t_fields *fields);
t_prints		ft_convert(intmax_t *data, t_fields *fields);
int				ft_print_field(t_prints *data_prt, t_fields *fields);
t_prints		ft_print_reset(void);
void			ft_parse_flags(t_fields *fields, const char **format);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               Convert by type                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_prints		ft_cvt_s(t_prints *data_prt, t_fields *fields);
t_prints		ft_cvt_c(t_prints *data_prt, t_fields *fields);
t_prints		ft_cvt_diu(t_prints *print, t_fields *fields);
t_prints		ft_cvt_xp(t_prints *data_prt, t_fields *fields);
t_prints		ft_cvt_o(t_prints *data_prt, t_fields *fields);

#endif
