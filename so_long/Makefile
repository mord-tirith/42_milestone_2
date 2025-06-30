#######################
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#######################

#	Basic Variables:
NAME		= so_long
PNAME		= So Long
SRC_DIR = src/
OBJ_DIR = .obj/
INC_DIR = inc/
MLX_DIR = minilibx-linux/

# File Variables:
PAR_FILES	= flood_fill.c load_map.c maparse.c ones_check.c unique_symbols.c
PARSER		= $(addprefix 0_parser/, $(PAR_FILES))

ERR_FILES = printer.c
ERRORS		= $(addprefix 1_error/, $(ERR_FILES))

MAP_FILES = reboot_map.c translate_walls.c
MAPPER		=	$(addprefix 2_mapper/, $(MAP_FILES))

GAM_FILES = draw_map.c input_control.c so_long.c
GAME			= $(addprefix 3_game/, $(GAM_FILES))

BOT_FILES = assets_boot.c map_boot.c mlx_boot.c
BOOT			= $(addprefix 4_boot/, $(BOT_FILES))

CLE_FILES	= cleaner.c
CLEANUP		= $(addprefix 5_cleanup/, $(CLE_FILES))

SRC_FILES	= $(PARSER) $(ERRORS) $(MAPPER) $(GAME) $(BOOT) $(CLEANUP)
SRC				= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))


# Compiler Variables:
CC				= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT			= ./.libft/libft.a

####################
#      ▜   ▗ ▗     #
#  ▛▌▀▌▐ █▌▜▘▜▘█▌  #
#  ▙▌█▌▐▖▙▖▐▖▐▖▙▖  #
#  ▌               #
####################

BLUE		:= $(shell tput setaf 111)
RED			:= $(shell tput setaf 160)
PINK		:= $(shell tput setaf 200)
CYAN		:= $(shell tput setaf 87)
YELLOW	:= $(shell tput setaf 220)
RESET		:= $(shell tput sgr0)

MAKEFLAGS += --no-print-directory

################
#      ▜       #
#  ▛▘▌▌▐ █▌▛▘  #
#  ▌ ▙▌▐▖▙▖▄▌  #
################

.PHONY: all true_all clean fclean re clean_install banner mlx

all:
	@if make -q true_all; then \
		echo "${BLUE}${PNAME} already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: $(NAME)

$(NAME): $(OBJ)
	@make banner
	@make mlx
	@make libft.a
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLX_FLAGS) $(LIBFT)
	@echo "${BLUE}${PNAME} installed${RESET}"

mlx:
	@if ls ./minilibx-linux/libmlx_Linux.a 1>/dev/null 2>&1; then \
		echo "${BLUE}Minilibx already installed${RESET}"; \
	else \
		echo "${YELLOW}Compiling MLX${RESET}"; \
		$(MAKE) -C $(MLX_DIR) 1>/dev/null 2>&1; \
		echo "${BLUE}MLX installed${RESET}"; \
	fi

libft.a:
	@echo "${YELLOW}Building Libft++${RESET}"
	@$(MAKE) -C ./.libft all 1>/dev/null 2>&1
	@echo "${BLUE} Libft++ installed${RESET}"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@if ls $(OBJ) 1>/dev/null 2>&1; then \
		rm -rfd $(OBJ_DIR); \
		echo "${YELLOW}.o files removed${RESET}"; \
	else \
		echo "${RED}Error: no .o files to remove at this moment${RESET}"; \
	fi

fclean: clean
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		rm -f $(NAME); \
		echo "${YELLOW}Uninstalled ${PNAME}${RESET}"; \
	else \
		echo "${RED}Error: ${PNAME} isn't installed${RESET}"; \
	fi

re: fclean all

clean_install:
	@make all
	@make clean

banner:
	@echo "${BLUE}░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⡴⣿⢯⡅⡔⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠀⠀⢀⣠⠶⢯⠁⠀⡀⠀⠀⠙⠂⠘⠽⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠀⣠⣾⠏⠘⠁⡀⢀⠉⢛⣢⣰⣶⡶⠀⠀⠈⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░⠀⣰⣿⡇⠀⠀⠰⠃⣴⣦⣄⣠⣼⠯⠥⠀⠀⠀⠀⢿⣄⠀⠀⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░⢠⣿⠃⣀⡠⢀⣀⣶⡬⣿⡶⠦⠶⠶⠼⣂⡤⣀⡀⠀⠙⢣⠀⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░⢸⡃⢸⠛⡜⡼⠛⠻⢧⣄⣉⢒⢤⡄⠀⠀⠈⠓⢯⣷⣀⢬⣇⠀⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⢿⢁⢎⠞⠁⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠙⣷⣯⢻⡄⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⣧⣢⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⢂⡇⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧⣷⠀⠀⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⢿⢿⡷⣄⠀⠀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣏⣰⣲⣿⣶⣌⡳⡀░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠋⠁⠀⠀⠀⠉⠙⠃░░░░░░░░░░░░░░░░░░░"
	@echo "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░"
	@echo "▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒"
	@echo "▓▓      ▓▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓"
	@echo "███████  ██  ████  ████████  ████████  ████  ██  ██    ██  ████  █"
	@echo "██      ████      █████████        ███      ███  ███   ███      ██"
	@echo "██████████████████████████████████████████████████████████████████${RESET}"
