CC:=cc
CFLAGS := -Wall -Wextra -Werror
SRC :=	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isany.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_write.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		ft_printf.c \
		ft_utils.c \
		ft_putnbr.c \
		ft_puthex.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_count_word.c \
		ft_sort.c \
		ft_math.c \

OBJ := $(patsubst %.c, %.o, $(SRC))
DEP = $(SRC:.c=.d)

NAME := libft.a

GREEN    := \033[32m
RESET    := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

clean:
	@rm -rf $(OBJ) $(DEP)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
