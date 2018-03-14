/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 18:28:00 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 18:28:00 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/print.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned int i;

	if (s)
	{
		i = ft_strlen(s);
		write(fd, s, i);
	}
}
