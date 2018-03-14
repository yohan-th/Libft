/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 17:31:26 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:12:40 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

static int	ft_read_file(char **str, int fd)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(BUFF_SIZE);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		*str = ft_strcat_free(*str, buf);
	}
	free(buf);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*tmp;
	int			ret;
	char		*free_str;

	if (!(line) || BUFF_SIZE < 0 || fd < 0 || (!str && !(str = ft_strnew(0))))
		return (-1);
	while (!(tmp = ft_strchr(str, '\n')))
	{
		ret = ft_read_file(&str, fd);
		if (ret == 0 && !(ft_strlen(str)))
			return (0);
		if (ret == 0)
			str = ft_strjoin(str, "\n");
		if (ret < 0)
			return (-1);
	}
	free_str = str;
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(tmp));
	str = ft_strdup(++tmp);
	free(free_str);
	return (1);
}
