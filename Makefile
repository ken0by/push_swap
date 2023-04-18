########## MAKEFILE -> FT_PRINTF ##########
LIB	=	ar rcs
RM	=	rm -f

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I ./include -I ./libft/include/ -g3 -fsanitize=address

NAME	=	push_swap

RR	=	ss.c pp.c ft_moves.c rr.c rrr.c ft_checker.c
SS	=	push_swap.c fill_lst.c ft_check.c ft_nbr_check.c lst.c ft_error.c

SRCS_DIR	=	./src/
SRCR_DIR	=	./rules/
SRCS	=	$(addprefix $(SRCS_DIR), $(SS))
SRCR	=	$(addprefix $(SRCR_DIR), $(RR))

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(SS:.c=.o) $(RR:.c=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
#INCLUDE	=	include/

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
all: $(OBJ_DIR) $(NAME)

$(LIBFT) : $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRCR_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	$(RM) $(OBJ)
	@make clean -C libft
	@rm -rf $(OBJ_DIR)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@rm -f $(OBJ_DIR)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
