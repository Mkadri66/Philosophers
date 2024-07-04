# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkadri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 20:28:18 by mkadri            #+#    #+#              #
#    Updated: 2023/11/17 20:11:30 by mkadri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  			= ft_printf.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

LIBFT_PATH		= ./libft
LIBFT			= ${LIBFT_PATH}/libft.a

SRCS			= ft_printf.c print_char.c print_hexa.c print_str.c  print_unsigned.c print_pointer.c

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus