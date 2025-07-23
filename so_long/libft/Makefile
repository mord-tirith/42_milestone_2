#######▘##▌#▜######
#▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘#
#▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌#
###################

NAME = libft.a
PNAME = Libft++
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../inc/

TMP_DIR = .tmp
SUB_LIB_DIRS = ./print ./lib ./gnl
SUB_LIBS = print/ft_printf.a lib/libft.a gnl/get_next_line.a

#####▜###▗#▗####
#▛▌▀▌▐ █▌▜▘▜▘█▌#
#▙▌█▌▐▖▙▖▐▖▐▖▙▖#
#▌##############


BLUE		:= $(shell tput setaf 111)
RED			:= $(shell tput setaf 160)
PINK		:= $(shell tput setaf 200)
CYAN		:= $(shell tput setaf 87)
YELLOW	:= $(shell tput setaf 220)
BANNER_Y:= $(shell tput setaf 214)
RESET		:= $(shell tput sgr0)

MAKEFLAGS += --no-print-directory

#####▜######
#▛▘▌▌▐ █▌▛▘#
#▌ ▙▌▐▖▙▖▄▌#
############

.PHONY: all print/ft_printf.a lib/libft.a gnl/get_next_line.a clean fclean re banner mclean

all:
	@if make -q $(NAME); then \
		echo "${BLUE}${PNAME} already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: $(NAME)

$(NAME):
	@rm -rf $(TMP_DIR)
	@make banner
	@mkdir -p $(TMP_DIR)
	@for dir in $(SUB_LIB_DIRS); do \
		(cd $$dir && make all_clean); \
	done
	@for lib in $(SUB_LIBS); do \
		(cd $(TMP_DIR) && ar -x ../$$lib); \
	done
	@ar rcs $(NAME) $(TMP_DIR)/*.o
	@echo "${BLUE}${PNAME} installed${RESET}"

print/ft_printf.a:
	@$(MAKE) -C print all_clean

lib/libft.a:
	@$(MAKE) -C lib all_clean

gnl/get_next_line.a:
	@$(MAKE) -C gnl all_clean

clean:
	@rm -rfd $(TMP_DIR)

fclean: clean
	@for dir in $(SUB_LIB_DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		rm -f $(NAME); \
		echo "${YELLOW}${PNAME} uninstalled"; \
	else \
		echo "${RED}Error: ${PNAME} isn't installed"; \
	fi

mclean: re clean

re: fclean all

banner:
	@echo "${BANNER_Y}░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "▒  ▒▒▒▒▒▒▒▒        ▒▒       ▒▒▒        ▒▒        ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒"
	@echo "▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓"
	@echo "▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓       ▓▓▓      ▓▓▓▓▓▓▓  ▓▓▓▓        ▓▓        ▓"
	@echo "▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓"
	@echo "▒        ▒▒        ▒▒       ▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒"
	@echo "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "                                                          ${CYAN}by thenriqu${RESET}"
