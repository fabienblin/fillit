# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fblin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:33:02 by fblin             #+#    #+#              #
#    Updated: 2016/02/14 13:47:11 by fblin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FBLIN	=	ft_exit.c

BONUS	=	ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		ft_lstiter.c	\
			ft_lstmap.c		\

SRC		=	ft_memset.c		ft_strcat.c		ft_isdigit.c	ft_striter.c	ft_putchar.c	\
			ft_bzero.c		ft_strncat.c	ft_isalnum.c	ft_striteri.c	ft_putstr.c		\
			ft_memcpy.c		ft_strlcat.c	ft_isascii.c	ft_strmap.c		ft_putendl.c	\
			ft_memccpy.c	ft_strchr.c		ft_isprint.c	ft_strmapi.c	ft_putnbr.c		\
			ft_memmove.c	ft_strrchr.c	ft_toupper.c	ft_strequ.c		ft_putchar_fd.c	\
			ft_memchr.c		ft_strstr.c		ft_tolower.c	ft_strnequ.c	ft_putstr_fd.c	\
			ft_memcmp.c		ft_strnstr.c	ft_memalloc.c	ft_strsub.c		ft_putendl_fd.c	\
			ft_strlen.c		ft_strcmp.c		ft_memdel.c		ft_strjoin.c	ft_putnbr_fd.c	\
			ft_strdup.c		ft_strncmp.c	ft_strnew.c		ft_strtrim.c	$(BONUS)		\
			ft_strcpy.c		ft_atoi.c		ft_strdel.c		ft_strsplit.c	$(FBLIN)		\
			ft_strncpy.c	ft_isalpha.c	ft_strclr.c		ft_itoa.c

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

INC		=	./includes

all		:	$(NAME)

$(NAME)	:
			gcc $(FLAGS) -c $(SRC) -I $(INC)
			ar rc $(NAME) $(OBJ)

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
