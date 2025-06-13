#######################
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#######################

#	Basic Variables:
NAME		= pipex
PNAME		= Pipex
SRC_DIR = src/
INC_DIR = inc/

# File Variables:
SRC_FILES	= error.c file_ctl.c memory_handle.c pipex.c special_split.c
SRC				= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES	= $(SRC:.c=.o)
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_FILES))


# Compiler Variables:
CC				= cc
CFLAGS		= -Wall -Wextra -Werror -g
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

.PHONY: all true_all clean fclean re mclean banner mlx

all:
	@if make -q true_all; then \
		echo "${BLUE}${PNAME} already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: $(NAME)

$(NAME): $(OBJ)
	@make banner
	@make libft.a
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "${BLUE}${PNAME} installed${RESET}"

libft.a:
	@echo "${YELLOW}Building Libft++${RESET}"
	@$(MAKE) -C ./libft all

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@if ls $(OBJ) 1>/dev/null 2>&1; then \
		rm -f $(OBJ); \
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

mclean:
	@make all
	@make clean

banner:
	@echo "${PINK}░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "▒▒ ▒▒       ▒▒        ▒       ▒▒        ▒  ▒▒▒▒  ▒▒ ▒▒"
	@echo "▓▓ ▓▓  ▓▓▓▓  ▓▓▓▓  ▓▓▓▓  ▓▓▓▓  ▓  ▓▓▓▓▓▓▓▓  ▓▓  ▓▓▓ ▓▓"
	@echo "██ ██       █████  ████       ██      █████    ████ ██"
	@echo "▓▓ ▓▓  ▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓  ▓▓▓ ▓▓"
	@echo "▒▒ ▒▒  ▒▒▒▒▒▒▒        ▒  ▒▒▒▒▒▒▒        ▒  ▒▒▒▒  ▒▒ ▒▒"
	@echo "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "                                           ${CYAN}by thenriqu${RESET}"

