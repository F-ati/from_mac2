NAME = minishell

CC = cc

 CFLAGS = -Wall -Wextra -Werror 

LDFLAGS = -lreadline

RM = rm -rf 

SRC = split_double_single.c minishell_utils.c execution.c all_command.c herdoc.c builtine_command.c unset.c export.c
 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) minishell.h
	make -C libft
	$(CC)  $(OBJ) libft/libft.a $(LDFLAGS) -o $(NAME)

clean:
	make -C libft clean
	$(RM) $(OBJ) 

fclean: clean
	make -C libft fclean
	$(RM) $(NAME) 

re: fclean all
