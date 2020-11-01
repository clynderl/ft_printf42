# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:11:42 by clynderl          #+#    #+#              #
#    Updated: 2020/08/13 19:02:52 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=	ft_atoi.c ft_bzero.c ft_isalpha.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strncpy.c ft_strlcat.c ft_memcmp.c \
		ft_tolower.c ft_isascii.c ft_memcpy.c ft_putendl.c ft_strcat.c ft_strequ.c ft_strnequ.c ft_toupper.c ft_strrchr.c \
		ft_isdigit.c ft_memdel.c ft_putendl_fd.c ft_strclr.c ft_striter.c ft_strnew.c ft_strjoin.c ft_strncmp.c ft_memmove.c \
		ft_atoi.c ft_isprint.c ft_putnbr.c ft_strcmp.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsplit.c ft_strstr.c \
		ft_bzero.c ft_itoa.c ft_memset.c ft_putnbr_fd.c ft_strcpy.c ft_strlen.c ft_memchr.c ft_strtrim.c ft_strnstr.c\
		ft_isalnum.c ft_memalloc.c ft_putchar.c ft_putstr.c ft_strdel.c ft_strsub.c ft_strncat.c ft_strchr.c ft_strstr.c ft_memccpy.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstaddend.c ft_lst_reverse.c ft_islower.c \
		ft_isupper.c ft_getnumsize.c ft_sqrt.c get_next_line.c ft_strndup.c ft_pow.c ft_strappend.c ft_itoa_base_unsigned.c ft_dtoa.c ft_strrealloc.c

OBJECTS=ft_atoi.o ft_bzero.o ft_isalpha.o ft_putchar_fd.o ft_putstr_fd.o ft_strdup.o ft_strncpy.o ft_strlcat.o ft_memcmp.o \
		ft_tolower.o ft_isascii.o ft_memcpy.o ft_putendl.o ft_strcat.o ft_strequ.o ft_strnequ.o ft_toupper.o ft_strrchr.o \
		ft_isdigit.o ft_memdel.o ft_putendl_fd.o ft_strclr.o ft_striter.o ft_strnew.o ft_strjoin.o ft_strncmp.o ft_memmove.o \
		ft_atoi.o ft_isprint.o ft_putnbr.o ft_strcmp.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strsplit.o ft_strstr.o \
		ft_bzero.o ft_itoa.o ft_memset.o ft_putnbr_fd.o ft_strcpy.o ft_strlen.o ft_memchr.o ft_strtrim.o ft_strnstr.o \
		ft_isalnum.o ft_memalloc.o ft_putchar.o ft_putstr.o ft_strdel.o ft_strsub.o ft_strncat.o ft_strchr.o ft_strstr.o ft_memccpy.o \
		ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_lstaddend.o ft_lst_reverse.o ft_islower.o \
		ft_isupper.o ft_getnumsize.o ft_sqrt.o get_next_line.o ft_strndup.o ft_pow.o ft_strappend.o ft_itoa_base_unsigned.o ft_dtoa.o ft_strrealloc.o

INCLUDES=includes/

all: ${NAME}

${NAME}: ${SRCS} ${INCLUDES}libft.h
		@gcc -Wall -Wextra -Werror -I${INCLUDES} -c ${SRCS}
		@ar rc ${NAME} ${OBJECTS}
		@ranlib ${NAME}

clean:
		@/bin/rm -f ${OBJECTS}

fclean: clean
		@/bin/rm -f ${NAME}

re: fclean all
