#######▘##▌#▜######
#▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘#
#▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌#
###################

NAME		= ft_printf.a
CFLAGS		= -Wall -Werror -Wextra -I../inc/
AR			= ar rcs
CC			= cc

OBJS 		= ./src/functions.o ./src/printer.o ./src/ft_cs.o ./src/ft_idu.o ./src/ft_xp.o	
SRCS		= $(OBJS:.o=.c)

#####▜###▗#▗####
#▛▌▀▌▐ █▌▜▘▜▘█▌#
#▙▌█▌▐▖▙▖▐▖▐▖▙▖#
#▌##############

BLUE		:= $(shell tput setaf 111)
RED			:= $(shell tput setaf 160)
PINK		:= $(shell tput setaf 200)
CYAN		:= $(shell tput setaf 87)
YELLOW	:= $(shell tput setaf 220)
RESET		:= $(shell tput sgr0)

MAKEFLAGS += --no-print-directory

#####▜######
#▛▘▌▌▐ █▌▛▘#
#▌ ▙▌▐▖▙▖▄▌#
############

.PHONY: all true_all clean fclean re all_clean banner

all:
	@if make -q $(NAME); then \
		echo "${BLUE}Ft_printf already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: banner $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "${BLUE}ft_printf installed${RESET}"

$(OBJS):%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if ls $(OBJS) 1>/dev/null 2>&1; then \
		rm -f $(OBJS); \
		echo "${YELLOW}ft_printf .o files removed${RESET}"; \
	else \
		echo "${RED}Error: no ft_printf .o files to remove${RESET}"; \
	fi

fclean:
	@if ls $(OBJS) 1>/dev/null 2>&1; then \
		make clean; \
	fi
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		rm -f $(NAME); \
		echo "${YELLOW}Uninstalled ft_printf${RESET}"; \
	else \
		echo "${RED}Error: ft_printf isn't installed${RESET}"; \
	fi

re:
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		make fclean; \
	fi
	@make true_all

all_clean: all clean

banner:
	@echo "${PINK}░        ░░        ░░░░░░       ░░░       ░░░        ░░   ░░░  ░░        ░░        ░";
	@echo "▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒    ▒▒  ▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒";
	@echo "▓      ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓       ▓▓▓       ▓▓▓▓▓▓  ▓▓▓▓▓  ▓  ▓  ▓▓▓▓▓  ▓▓▓▓▓      ▓▓▓";
	@echo "█  ███████████  █████████  ████████  ███  ██████  █████  ██    █████  █████  ███████";
	@echo "█  ███████████  █       █  ████████  ████  ██        ██  ███   █████  █████  ███████";
	@echo "                                                                         ${CYAN}by thenriqu${RESET}";
