NAME	=	fillit

FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c

HDR		=	fillit.h

LIB		=	./lib/

ARCHIVE	=	$(LIB)libft.a

INC		=	$(LIB)includes/

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	libft
		gcc -c $(SRC) -L $(LIB) -I $(INC)
		gcc -o $(NAME) $(OBJ) $(HDR) -I $(INC) $(ARCHIVE)

libft	:
		make -C $(LIB)

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all

test	:	
