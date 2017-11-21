# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fablin <fablin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 11:25:26 by fablin            #+#    #+#              #
#    Updated: 2017/11/19 19:57:46 by fablin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

INC_DIR =	./inc/

OBJ_DIR =	./obj/

SRC_DIR =	./src/

FABLIN =	ft_exit.c		ft_realloc.c	ft_lstpush.c	ft_lstdup.c		\
			ft_swapptr.c

BONUS =		ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		\
			ft_lstiter.c	ft_lstmap.c

C_FILES =	ft_memset.c		ft_strcat.c		ft_isdigit.c	ft_striter.c	\
			ft_putchar.c 	ft_bzero.c		ft_strncat.c	ft_isalnum.c	\
			ft_striteri.c	ft_putstr.c		ft_memcpy.c		ft_strlcat.c	\
			ft_isascii.c	ft_strmap.c		ft_putendl.c	ft_memccpy.c	\
			ft_strchr.c		ft_isprint.c	ft_strmapi.c	ft_putnbr.c		\
			ft_memmove.c	ft_strrchr.c	ft_toupper.c	ft_strequ.c		\
			ft_putchar_fd.c	ft_memchr.c		ft_strstr.c		ft_tolower.c	\
			ft_strnequ.c	ft_putstr_fd.c	ft_memcmp.c		ft_strnstr.c	\
			ft_memalloc.c	ft_strsub.c		ft_putendl_fd.c	ft_strlen.c		\
			ft_strcmp.c		ft_memdel.c		ft_strjoin.c	ft_putnbr_fd.c	\
		 	ft_strdup.c		ft_strncmp.c	ft_strnew.c		ft_strtrim.c	\
			ft_strcpy.c		ft_atoi.c		ft_strdel.c		ft_strsplit.c	\
			ft_strncpy.c	ft_isalpha.c	ft_strclr.c		ft_itoa.c		\
			$(BONUS)		$(FABLIN)
			
O_FILES =	$(C_FILES:.c=.o)

SOURCES =	$(addprefix $(SRC_DIR), $(C_FILES))

OBJECTS =	$(addprefix $(OBJ_DIR), $(O_FILES))

CC_FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(O_FILES)
	@ar rc $(NAME) $(O_FILES)
	@mkdir -p $(OBJ_DIR)
	@mv $(O_FILES) $(OBJ_DIR)
	@echo "\n===> LIBFT HAS BEEN COMPILED <===\n"

%.o: $(SRC_DIR)%.c
	@gcc $(CC_FLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re