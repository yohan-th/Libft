/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rmvpath.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 02:24:03 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 02:36:09 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/string.h"

/*
** ft_removepath : le while prend un compte le dernier '/' en fin de path
** et le conserve. Ex ~/path/de/mon/fichier/ --> fichier/
*/

char *ft_removepath(char *str)
{
	if (!ft_strchr(str, '/') && (ft_strchr(str, '/') + 1) == '\0')
		return (str);
	else
	{
		while (ft_strchr(str, '/') != 0 && ft_strlen(ft_strchr(str, '/')) != 1)
				str = ft_strchr(str, '/') + 1;
			return (str);
	}
}

