# Standard
NAME				= push_swap

# Directories
LIBFT				= ./Libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
SRCS		=	$(SRC_DIR)push.c \
						$(SRC_DIR)rev_rotate.c \
						$(SRC_DIR)rotate.c \
						$(SRC_DIR)sort_stacks.c \
						$(SRC_DIR)sort_stacks2.c \
						$(SRC_DIR)sort_three.c \
						$(SRC_DIR)swap.c \
						$(SRC_DIR)handle_errors.c \
						$(SRC_DIR)init_a_to_b.c \
						$(SRC_DIR)init_b_to_a.c \
						$(SRC_DIR)push_swap.c \
						$(SRC_DIR)split.c \
						$(SRC_DIR)stack_init.c \
						$(SRC_DIR)stack_utils.c

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./Libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./Libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re