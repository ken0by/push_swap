########## MAKEFILE -> FT_PRINTF ##########
LIB	=	ar rcs
RM	=	rm -f

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I ./include -I ./libft/libft.h

NAME	=	push_swap

SRC	=	push_swap.c fill_lst.c ss.c
OBJ	=	$(SRC:.c=.o)
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
INCLUDE	=	include/

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

$(LIBFT) : $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
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
