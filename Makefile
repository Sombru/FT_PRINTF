# Library name
NAME = libftprintf.a

# Compiler
CC    = cc
FLAGS = -g -Wall -Wextra -Werror
#-Wall -Wextra -Werror

# Lib
LIB = ar rcs

# Sources
SRC = ft_printf.c convert.c parse_flags.c debug.c \
	  print_char.c print_string.c print_digit.c print_hex.c print_pointer.c print_unsigned.c

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Objects
OBJ_PATH = obj/
OBJ 	 = $(SRC:.c=.o)
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

# Targets
all: $(OBJ_PATH) $(LIBFT) $(NAME)

bonus: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(LIB) $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH) --no-print-directory

fclean: clean
	@rm -f $(NAME) ft_printf.out
	@make fclean -C $(LIBFT_PATH) --no-print-directory 

debug: $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o ft_printf.out

re: fclean all

.PHONY: all clean fclean re