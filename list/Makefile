########## MAKEFILE -> FT_PRINTF ##########
LIB	=	ar rcs
RM	=	rm -f

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

SRC	=	push_swap.c ss.c
OBJ	=	$(SRC:.c=.o)
INCLUDE	=	push_swap.h

##########COLORES##########
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

##########REGLAS##########
all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	make -C libft
##	@$(CC) $(CFLAGS) -o $(NAME)	##
	@$(LIB) $(NAME) $(OBJ)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	$(RM) $(OBJ)
	@make clean -C libft
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
