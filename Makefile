# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 15:21:05 by ybeaure           #+#    #+#              #
#    Updated: 2016/06/24 02:15:43 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft
LIB = $(LIBPATH)/libft.a

NAME = ft_ls

CC = @gcc

CFLAGS = # -Wall -Wextra -Werror

LDFLAGS = -L $(LIBPATH) -lft

SRC =  main.c\
	   ft_init_struct.c\
		ft_handle_option.c\
		ft_find_options.c\
		open.c\
		ft_check_folder.c\
		ft_add_data.c\

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	@make -C $(LIBPATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBPATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBPATH)

re: fclean all

.PHONY: all re clean flcean
