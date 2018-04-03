# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/14 01:36:40 by ythollet     #+#   ##    ##    #+#        #
#    Updated: 2018/03/14 23:28:04 by ythollet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a

DIR_CHR =	Char/
DIR_PRTF =	Ft_printf/
DIR_GNL =	GetNextLine/
DIR_INC =	Includes/
DIR_LST =	List/
DIR_MATH =	Maths/
DIR_MEM =	Memory/
DIR_PUT =	Print/
DIR_STR =	String/

CHR = 	ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_islower.c \
		ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c ft_toupper.c \
		ft_size_wchar.c ft_nbrchar.c

GNL =	get_next_line.c

LST =	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c

MEM =	ft_bzero.c ft_memset.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memalloc.c ft_memccpy.c

PUT =	ft_putchar.c ft_putchar_fd.c ft_putnbr_signed.c ft_putnbr_unsigned.c \
		ft_putstr.c ft_putstr_fd.c ft_putwchar.c ft_putwstr.c ft_putchar_dup.c

STR =	ft_strcat.c ft_strcmp.c ft_strdup.c ft_strlen.c \
		ft_strncat.c ft_strnequ.c ft_strstr.c ft_wstrncpy.c\
		ft_strchr.c ft_strcpy.c ft_strjoin.c ft_wstrcpy.c ft_strjoin_mltp.c \
		ft_strncmp.c ft_strnew.c ft_strrev.c ft_strsub.c ft_wstrsub.c \
		ft_strclr.c ft_strdel.c ft_strlcat.c ft_strnbr.c ft_strcat_free.c \
		ft_strncpy.c ft_strsplit.c ft_strtrim.c ft_wstrlen.c ft_wstrdup.c

PRTF =	ft_printf.c pf_parse.c pf_type.c pf_convert.c pf_print_field.c \
		pf_struct.c pf_cvt_c.c pf_cvt_s.c pf_cvt_o.c pf_cvt_diu.c pf_cvt_xp.c

MATH =	ft_atoi.c ft_itoa.c ft_lenint.c ft_lenint_base.c ft_sqrt.c ft_utoa.c \
		ft_digitlen.c

SRC = 	$(addprefix $(DIR_CHR), $(CHR)) $(addprefix $(DIR_GNL), $(GNL)) \
		$(addprefix $(DIR_LST), $(LST)) $(addprefix $(DIR_STR), $(STR)) \
		$(addprefix $(DIR_MEM), $(MEM)) $(addprefix $(DIR_PUT), $(PUT)) \
		$(addprefix $(DIR_MATH), $(MATH)) $(addprefix $(DIR_PRTF), $(PRTF))

OBJ = 	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

./%.o : ./%.c
	@gcc $(CFLAGS) -I $(DIR_INC) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
