NAME = push_swap

NAME_BONUS = checker

SRCS = push_swap.c \
		push_swap_read_input.c \
		push_swap_read_input_utils.c \
		push_swap_push_elem.c \
		push_swap_sort_stack_a.c \
		push_swap_sort_stack_b.c \
		push_swap_utils.c \
		push_swap_operation.c

SRCS_BOUNS = checker.c \
		push_swap_read_input.c \
		push_swap_read_input_utils.c \
		push_swap_operation.c

OBJS = $(SRCS:.c=.o)

OBJ_BONUS = checker.o

CC = cc

LINKS = -L ./libft -lft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) -o $@ $(OBJS) $(FLAGS) $(LINKS)

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

.PHONY: clean fclean bonus re

clean:
	rm -f $(SRCS:.c=.o) $(SRCS_BOUNS:.c=.o)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(SRCS_BOUNS) -o $(NAME_BONUS) $(FLAGS) $(LINKS)

re: fclean all bonus