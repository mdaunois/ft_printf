# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/01/15 16:46:47 by mdaunois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c\
	   	ft_itoa_long.c\
		ft_itoa_uim.c\
		ft_itoabase_uintmax.c\
		ft_itoabase.c\
		ft_itoabase_long.c\
		recup_val.c\
		recup_val_suite.c\
		aplication_des_flag.c\
		aplication_des_flag_suite.c\
		convertion.c\
		outil.c\
		recup_flag.c\
		modif_val.c\
		flag_a_appliquer.c\
		flagbig_c.c

OBJ = $(SRCS:.c=.o)

#FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
#	gcc $(OBJ) libft/libft.a -o test
	ar rc $(NAME) $(OBJ) libft/libft.a libft/*.o

 %.o: %.c
	gcc -c $< $(FLAGS) -I libft/includes

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
