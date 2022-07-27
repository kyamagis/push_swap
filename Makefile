CC = cc
CFLAGS = -Wall -Wextra -Werror 
#CFLAGS = -fsanitize=address
INCLUDE = -I$(PUSH_HEADERS) -I$(LIBFT_HEADER) -I$(PRINT_HEADER)
LDFLAGS = -L$(LIBFT_DIRECTORY) -lft -L$(PRINT_DIRECTORY)
SRCS = ./src/main.c\
		./src/quick_sort.c\
		./src/coordinate_compression.c\
		./src/make_a_b_lst.c\
		./src/ft_push_swap.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
NAME = push_swap
BONUS_NAME = push_swap_bonus

PUSH_HEADERS = ./includes/

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)

PRINT = $(PRINT_DIRECTORY)libftprintf.a
PRINT_DIRECTORY = ./printf/
PRINT_HEADER = $(PRINT_DIRECTORY)

all: libft print $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) $(PRINT) $(LIBFT) -o $(NAME)

# %.o:%.c 
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LDFLAGS) $(GNL) -o $(NAME)




# bonus: fclean libft print $(BONUS_NAME)
	
# $(BONUS_NAME): $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJS) $(LDFLAGS) $(PRINT) $(LIBFT) -o $(BONUS_NAME)

libft:
	make -C $(LIBFT_DIRECTORY)

print:
	make -C $(PRINT_DIRECTORY)

clean:
	make -C $(LIBFT_DIRECTORY) clean
	make -C $(PRINT_DIRECTORY) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIRECTORY) fclean
	make -C $(PRINT_DIRECTORY) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus libft print