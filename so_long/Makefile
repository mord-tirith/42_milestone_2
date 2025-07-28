#######################
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#######################

#	Basic Variables:
NAME				= so_long
BONUS_NAME	= so_long_bonus
PNAME				= So Long
SRC_DIR			= src/
BON_DIR			= bonus_src/
BON_OBJ_DIR = .bonus_obj/
OBJ_DIR			= .obj/
INC_DIR			= inc/
MLX_DIR			= minilibx-linux/

# File Variables:
PAR_FILES	= file.c flood.c maparse.c ones.c uniques.c
PARSER		= $(addprefix 0_parser/, $(PAR_FILES))

ERR_FILES = printer.c 
ERRORS		= $(addprefix 1_error/, $(ERR_FILES))

BOT_FILES = boot.c detail_map.c map_boot.c player_boot.c reboot_map.c swiper.c
BOOT			= $(addprefix 2_boot/, $(BOT_FILES))

DRA_FILES	= looper.c map_draw.c player_draw.c
DRAW			= $(addprefix 3_draw/, $(DRA_FILES))

GAM_FILES = assets.c cleanup.c hooks.c so_long.c
GAME			= $(addprefix 4_game/, $(GAM_FILES))

SRC_FILES	= $(PARSER) $(ERRORS) $(BOOT) $(DRAW) $(GAME) 
SRC				= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))


BONUS_PAR	= file.c flood.c maparse.c ones.c uniques.c valids.c
B_PARSER	= $(addprefix 0_parser/, $(BONUS_PAR))

BONUS_ERR	= printer.c 
B_ERRORS	= $(addprefix 1_error/, $(BONUS_ERR))

BONUS_BOT	= boot.c detail_map.c map_boot.c mob_boot.c player_boot.c reboot_map.c swiper.c
B_BOOT		= $(addprefix 2_boot/, $(BONUS_BOT))

BONUS_ASE	= boot_assets.c load_map.c load_mobs.c load_player.c others.c
B_ASSETS	= $(addprefix 3_assets/, $(BONUS_ASE))

BONUS_DRA = background.c enemies.c foreground.c looper.c midground.c 
B_DRAW		= $(addprefix 4_draw/, $(BONUS_DRA))

BONUS_GAM	= control.c loop.c so_long_bonus.c
B_GAME		= $(addprefix 5_game/, $(BONUS_GAM))

BONUS_EXE	= assets.c manager.c pointers.c
B_EXIT		= $(addprefix 6_exit/, $(BONUS_EXE))

BON_FILES	= $(B_PARSER) $(B_ERRORS) $(B_BOOT) $(B_ASSETS) $(B_DRAW) $(B_GAME) $(B_EXIT)
BONUS_SRC	= $(addprefix $(BON_DIR), $(BON_FILES))
BONUS_OBJ	:= $(patsubst $(BON_DIR)%.c, $(BON_OBJ_DIR)%.o, $(BONUS_SRC))


# Compiler Variables:
CC				= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT			= ./libft/libft.a

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

.PHONY: all true_all clean fclean re clean_install banner mlx bonus

all:
	@if make -q true_all; then \
		echo "${BLUE}${PNAME} already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: $(NAME)

bonus: $(BONUS_OBJ)
	@if make -q bonus; then \
		echo "${BLUE}${PNAME} bonus already up to date${RESET}"; \
		else \
			make banner; \
			make mlx; \
			make libft.a; \
			$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(MLX_FLAGS) $(LIBFT); \
	fi

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
	@$(MAKE) -C ./libft/ 1>/dev/null 2>&1
	@echo "${BLUE} Libft++ installed${RESET}"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BON_OBJ_DIR)%.o: $(BON_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ] || [ -d "$(BON_OBJ_DIR)" ]; then \
		rm -rfd $(OBJ_DIR) $(BON_OBJ_DIR); \
		echo "${YELLOW}.o files removed${RESET}"; \
	else \
		echo "${RED}Error: no .o files to remove at this moment${RESET}"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ] || [ -f "$(BONUS_NAME)" ]; then \
		rm -f $(NAME) $(BONUS_NAME); \
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
	@echo "██████████████████████████████████████████████████████████████████"
	@echo "                                                       ${PINK}by thenriqu${RESET}"
