# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 18:01:23 by ybeaure           #+#    #+#              #
#    Updated: 2016/06/14 17:51:30 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME	=	libft.a
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

SDIR	=	./src/
IDIR	=	./includes/
ODIR	=	./obj/

I		=	-I $(IDIR)

EXT		=	Makefile
EXT		+=	$(IDIR)libft.h

SRC		=	ft_atoi.c\
			ft_itoa.c\
			ft_memcpy.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\

OBJ		=	$(SRC:.c=.o)
	S		=	$(addprefix $(SDIR), $(SRC))
	O		=	$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

test: all
	@$(CC) $(FLAGS) test/main.c -o test/test $I -L. -lft
	@./test/test

creating:
	@echo " - compiling sources\c"

$(NAME): creating $(O) $(EXT)
	@echo "\n - Creating library..."
	@ar rc $(NAME) $(O)
	@echo " - Optimizing..."
	@ranlib $(NAME)
	@echo "libft done.\n"


$(ODIR)%.o: $(SDIR)%.c $(EXT)
	@echo ".\c"
	@$(CC) $(FLAGS) -c -o $@ $< $(I)

$(O): | $(ODIR)
$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)

re: fclean all
