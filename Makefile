# SETUP
NAME		=	minishell
LIBFT		=	$(LFT_PATH)libft.a

CFLAGS		=	-Wall -Wextra -Werror -g3
RM			=	rm -rf
LIB_CF		=	-L $(LFT_PATH) -lft
READLINE_CF	=	-lreadline -lhistory


INCLUDES	=	-I$(HEADER_DIR) -I$(LFT_PATH)

# FILES AND PATH
LFT_PATH 	=	libft/

HEADER_FILE	=	minishell.h struct.h
HEADER_DIR	=	include/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_FILE))

SRC_FILES	=	lexer/lexer_list.c \
				lexer/lexer_tokenizer.c \
				lexer/lexer_utils.c \
				lexer/lexer.c \
				lexer/lexer_list_utils.c \
				main/mini_utils.c \
				main/minishell.c \
				main/error.c \
				main/signal.c \
				parser/expander.c \
				parser/parser_utils.c \
				parser/parser.c \
				parser/polisher.c \
				executor/executor.c \
				executor/exec_utils.c \
				executor/redirect.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c
SRC_DIR		=	src/
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.o))


# RULES

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) Makefile
		@mkdir -p $(OBJ_DIR) obj/main/ obj/executor/ obj/lexer/ obj/parser/ obj/builtins/;
		@cc $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		cc $(OBJ) $(CFLAGS) $(LIB_CF) $(READLINE_CF) -o $(NAME)
		@echo "\n$(GREEN)Minishell created!$(DEFAULT)\n"

$(LIBFT): $(LFT_PATH)
		@make -C $(LFT_PATH)
		@echo "\n$(GREEN)Libft created!$(DEFAULT)\n"

clean: 
		@make clean -C $(LFT_PATH)
		@echo "\n$(RED)Libft objects removed!$(DEFAULT)\n"
		@$(RM) $(OBJ_DIR)
		@echo "\n$(RED)Minishell objects removed!$(DEFAULT)\n\n"

fclean: clean
		@make fclean -C $(LFT_PATH)
		@echo "\n$(RED)All libraries removed!$(DEFAULT)\n"
		@$(RM) $(NAME)
		@echo "\n$(RED)Minishell removed!$(DEFAULT)\n\n"

re: fclean all

.PHONY: all clean fclean re

# COLORS
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
DEFAULT	=	\033[0m
