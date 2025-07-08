#######▘##▌#▜######
#▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘#
#▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌#
###################

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../inc/

OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o \
	   ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o \
	   ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o \
	   ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o \
	   ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o \
	   ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew_bonus.o \
		 ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o \
		 ft_lstadd_back_bonus.o 	ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o \
		 ft_lstmap_bonus.o ft_strstr.o

SRCS = $(OBS:.o=.c)

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

all:
	@if make -q $(NAME); then \
		echo "${BLUE}Libft already up to date${RESET}"; \
	else \
		make true_all; \
	fi

true_all: banner $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "${BLUE}Libft installed${RESET}"

$(OBJS):%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	@if ls $(OBJS) 1>/dev/null 2>&1; then \
		rm -f $(OBJS); \
		echo "${YELLOW}libft .o files removed${RESET}"; \
	else \
		echo "${RED}Error: no libft .o files to remove${RESET}"; \
	fi

fclean:
	@if ls $(OBJS) 1>/dev/null 2>&1; then \
		make clean; \
	fi
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		rm -f $(NAME); \
		echo "${YELLOW}Uninstalled libft${RESET}"; \
	else \
		echo "${RED}Error: Libft isn't installed${RESET}"; \
	fi

re:
	@if ls $(NAME) 1>/dev/null 2>&1; then \
		make fclean; \
	fi
	@make true_all

all_clean: all clean

.PHONY: all clean fclean re banner all_clean

banner:
	@echo "${PINK}";
	@echo "░  ░░░░░░░░        ░░       ░░░        ░░        ░";
	@echo "▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒";
	@echo "▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓       ▓▓▓      ▓▓▓▓▓▓▓  ▓▓▓▓";
	@echo "█  ███████████  █████  ████  ██  ███████████  ████";
	@echo "█        ██        ██       ███  ███████████  ████";
	@echo "                                       ${CYAN}by thenriqu${RESET}";
