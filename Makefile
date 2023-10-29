NAME	= push_swap
LIBFT	= ./Libft/libft.a
SRC_DIR	= srcs
OBJ_DIR	= obj
INC_DIR	= inc
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR)
SRCS	= $(wildcard $(SRC_DIR)/*.c)
OBJ		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

.PHONY: start all clean fclean re

all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C ./Libft

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C ./Libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all