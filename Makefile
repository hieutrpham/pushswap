CC = cc -Wall -Werror -Wextra -MMD -MP
NAME = push_swap
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
INCLUDE = -I. -Iinclude/ -I$(LIBFT_PATH)

GREEN := \033[32m
RESET := \033[0m

SRC = main.c \
		errors.c \
		utils.c \
		parser.c \
		stack_op.c \
		algo.c \
		algo_helper.c \
		post_algo.c \
		minisort.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
DEP = $(addprefix $(OBJ_PATH), $(SRC:.c=.d))

.SECONDARY: $(OBJS) $(DEP)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $^ -o $@ $(LIBFT)
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@printf "$(GREEN)$(LIBFT) created successfully!$(RESET)\n"

clean:
	@rm -rf $(OBJ_PATH) $(DEP) 
	@make -C $(LIBFT_PATH) clean
	@printf "$(GREEN)clean$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@printf "$(GREEN)fclean$(RESET)\n"

re: fclean all

debug:
	@make CC="$(CC) -g" re

asan:
	@make CC="$(CC) -fsanitize=address" re

.PHONY: all re clean fclean debug asan
-include $(DEP)
