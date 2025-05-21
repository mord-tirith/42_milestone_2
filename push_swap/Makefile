
# Variables:

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

BLUE		:= $(shell tput setaf 111)
RED			:= $(shell tput setaf 160)
PINK		:= $(shell tput setaf 200)
CYAN		:= $(shell tput setaf 87)
YELLOW	:= $(shell tput setaf 220)
RESET		:= $(shell tput sgr0)

MAKEFLAGS += --no-print-directory

SRCS	= boot.c brains.c compute_cost.c error.c minilib_1.c minilib_2.c more_stack_utils.c \
				mover.c push_swap.c stack_utils.c updater.c validation.c ops/push_ab.c \
				ops/reverse_rotate_ab.c ops/rotate_ab.c ops/swap_ab.c
SRCS_DIR		= src/
SRCS_FILES	= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS				= $(SRCS_FILES:.c=.o)

.PHONY: all true_all clean fclean re banner clean_install

all:
	@if make -q true_all; then \
		echo "${BLUE}Push Swap already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: $(NAME)

$(NAME): $(OBJS)
	@make banner
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${BLUE}Push Swap installed${RESET}"

$(OBJS):%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if ls $(OBJS) 1>/dev/null 2>&1; then \
		rm -f $(OBJS); \
		rm -f $(BONUS_OBJS); \
		echo "${YELLOW}.o files removed${RESET}"; \
	else \
		echo "${RED}Error: no .o files to remove at this moment${RESET}"; \
	fi

fclean: clean
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		rm -f $(NAME); \
		echo "${YELLOW}Uninstalled Push Swap${RESET}"; \
	else \
		echo "${RED}Error: Push Swap isn't installed${RESET}"; \
	fi

re: fclean all

clean_install:
	@make all
	@make clean

banner:
	@echo "${PINK}░       ░░░  ░░░░  ░░░      ░░░  ░░░░  ░░░░░░░░░      ░░░  ░░░░  ░░░      ░░░       ░░";
	@echo "▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒  ▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒";
	@echo "▓       ▓▓▓  ▓▓▓▓  ▓▓▓      ▓▓▓        ▓▓▓   ▓▓▓      ▓▓▓        ▓▓  ▓▓▓▓  ▓▓       ▓▓";
	@echo "█  ████████  ████  ████████  ██  ████  ██████████████  ██   ██   ██        ██  ███████";
	@echo "█  █████████      ████      ███  ████  █████████      ███  ████  ██  ████  ██  ███████";
	@echo "                                                                           ${CYAN}by thenriqu${RESET}";
