# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 19:40:33 by eparisot          #+#    #+#              #
#    Updated: 2018/04/20 02:10:00 by eparisot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRCS	=	srcs/main.c \
			srcs/read.c \
			srcs/parse.c \
			srcs/check.c \
			srcs/visu.c \
			GNL/get_next_line.c \
			SDL/sdl_lem_in.c

OBJS	=	$(SRCS:.c=.o)

LIBS	=	libft/libft.a \
			printf/libftprintf.a \
			`SDL2-config --libs`

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror `sdl2-config --cflags`

## some useful `flags` for memory verifications
## -O1 -g -fsanitize=address \
## -fno-omit-frame-pointer \
## -fsanitize-address-use-after-scope \

all		:	$(NAME) $(LIBS)

$(NAME)	:	$(OBJS) $(LIBS)
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBS)	:
	cd libft && make && cd ../printf && make && cd ..

clean	:
	$(RM) $(OBJS) && cd libft/ && make clean && \
cd ../printf && make clean && cd ..

fclean	:	clean
	$(RM) $(NAME) libft/libft.a printf/libftprintf.a

re		:	fclean all
