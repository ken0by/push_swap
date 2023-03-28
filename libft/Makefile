LIB = ar rcs
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./ft_printf/include -I ./gnl/include

NAME = libft.a

FT	=	./ft/ft_atoi.c ./ft/ft_bzero.c ./ft/ft_calloc.c ./ft/ft_isalnum.c ./ft/ft_isalpha.c ./ft/ft_isascii.c ./ft/ft_isdigit.c ./ft/ft_isprint.c ./ft/ft_itoa.c ./ft/ft_split.c ./ft/ft_tolower.c ./ft/ft_toupper.c
LST	=	./lst/ft_lstadd_back.c ./lst/ft_lstadd_front.c ./lst/ft_lstclear.c ./lst/ft_lstdelone.c ./lst/ft_lstiter.c ./lst/ft_lstlast.c ./lst/ft_lstmap.c ./lst/ft_lstnew.c ./lst/ft_lstsize.c
MEM	=	./mem/ft_memchr.c ./mem/ft_memcmp.c ./mem/ft_memcpy.c ./mem/ft_memmove.c ./mem/ft_memset.c
PUT	=	./put/ft_putchar_fd.c ./put/ft_putendl_fd.c ./put/ft_putnbr_fd.c ./put/ft_putstr_fd.c
STR	=	./str/ft_strchr.c ./str/ft_strdup.c ./str/ft_striteri.c ./str/ft_strjoin.c ./str/ft_strlcat.c ./str/ft_strlcpy.c ./str/ft_strlen.c ./str/ft_strmapi.c ./str/ft_strncmp.c ./str/ft_strnstr.c ./str/ft_strrchr.c ./str/ft_strtrim.c ./str/ft_substr.c
FT_PRINTF	=	./ft_printf/src/ft_printf.c ./ft_printf/src/ft_print_char.c ./ft_printf/src/ft_print_nbr.c
GNL	=	./gnl/src/get_next_line.c ./gnl/src/get_next_line_bonus.c ./gnl/src/get_next_line_utils.c ./gnl/src/get_next_line_utils_bonus.c

SRC	=	$(FT) $(LST) $(MEM) $(PUT) $(STR) $(FT_PRINTF) $(GNL)
OBJ = $(SRC:.c=.o)
INCLUDE = libft.h ./ft_printf/ft_printf.h ./gnl/get_next_line.h ./gnl/get_next_line_bonus.h

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
