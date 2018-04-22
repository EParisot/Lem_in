# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 19:40:33 by eparisot          #+#    #+#              #
#    Updated: 2018/04/22 14:34:45 by eparisot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRCS	=	srcs/main.c \
			srcs/read.c \
			srcs/parse.c \
			srcs/check.c \
			srcs/visu.c \
			srcs/lem_in.c \
			GNL/get_next_line.c \
			SDL/sdl_lem_in1.c \
			SDL/sdl_lem_in2.c \
			SDL/sdl_lem_in3.c

OBJS	=	$(SRCS:.c=.o)

LIBS	=	libft/libft.a \
			printf/libftprintf.a \
			`SDL2-config --libs` \
			-lSDL2_ttf

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror `sdl2-config --cflags`

## some useful `flags` for memory verifications
## -O1 -g -fsanitize=address \
## -fno-omit-frame-pointer \
## -fsanitize-address-use-after-scope \

all		:	$(LIBS) $(NAME)

$(NAME)	:	$(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBS)	:
	$(MAKE) -C libft && $(MAKE) -C printf

clean	:
	$(RM) $(OBJS) && $(MAKE) clean -C libft && $(MAKE) clean -C printf

fclean	:	clean
	$(RM) $(NAME) libft/libft.a printf/libftprintf.a

re		:	fclean all
