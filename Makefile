# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 15:21:05 by ybeaure           #+#    #+#              #
#    Updated: 2016/06/28 08:59:49 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft
LIB = $(LIBPATH)/libft.a

NAME = ft_ls

CC = @gcc

CFLAGS = # -Wall -Wextra -Werror

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		ft_init_struct.c\
		ft_handle_option.c\
		ft_find_options.c\
		open.c\
		ft_check_folder.c\
		ft_add_data.c\
		ft_display.c\
		ft_display_r.c\
		ft_display_rights.c\
		ft_display_all.c\
		ft_display_link_count.c\
		ft_display_ownership.c\
		ft_display_link.c\
		ft_make_time.c\
		ft_display_size.c\
		dlist_new.c\
		fuck_the_norm.c\

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
