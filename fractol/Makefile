#######################
#                     #
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#                     #
#######################

#	Basic Variables:
NAME		= fractol
SRC_DIR = src/
INC_DIR = inc/
MLX_DIR = minilibx-linux/

# File Variables:
SRC_FILES	= main.c basic.c medium.c minilib.c
SRC				= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				= $(SRC:.c=.o)


# Compiler Variables:
CC				= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

################
#              #
#      ▜       #
#  ▛▘▌▌▐ █▌▛▘  #
#  ▌ ▙▌▐▖▙▖▄▌  #
#              #
################

all : $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLX_FLAGS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
