NAME = fillit

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = main.c					\
 			ft_print_solution.c		\
 			ft_solve.c				\
 			ft_test_input.c			\
 			ft_position.c			\
			ft_set_env.c			\
			ft_new_env.c			\
			ft_new_tetri.c

O_FILES = $(SRC_FILES:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

I_LIBFT = -Ilibft

LIBFT = -Llibft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) -o $(NAME) $^ -I$(INC_DIR) $(LIBFT)
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
