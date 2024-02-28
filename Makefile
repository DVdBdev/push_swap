NAME				= push_swap
LIBFT				= ./Libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f
SRCS 				= 	$(SRC_DIR)handle_errors.c \
						$(SRC_DIR)init_a_to_b.c \
						$(SRC_DIR)init_b_to_a.c \
						$(SRC_DIR)push_swap.c \
						$(SRC_DIR)split.c \
						$(SRC_DIR)stack_init.c \
						$(SRC_DIR)stack_utils.c \
						$(SRC_DIR)push.c \
						$(SRC_DIR)rev_rotate.c \
						$(SRC_DIR)rotate.c \
						$(SRC_DIR)sort_stacks.c \
						$(SRC_DIR)sort_stacks2.c \
						$(SRC_DIR)sort_three.c \
						$(SRC_DIR)swap.c

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					@make all

$(LIBFT):
					@make -C ./Libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "$(GREEN)✨ push_swap compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./Libft
					@echo "$(RED)🗑️  object files$(DEF_COLOR)"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "$(RED)🗑️  executables$(DEF_COLOR)"

re: 				fclean all

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.PHONY: 			start all clean fclean re