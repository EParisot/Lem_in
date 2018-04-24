# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 19:40:33 by eparisot          #+#    #+#              #
#    Updated: 2018/04/24 05:19:17 by eparisot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRCS	=	srcs/main.c \
			srcs/read.c \
			srcs/parse.c \
			srcs/check.c \
			srcs/visu.c \
			srcs/lem_in1.c \
			srcs/lem_in2.c \
			GNL/get_next_line.c \
			SDL/sdl_lem_in1.c \
			SDL/sdl_lem_in2.c \
			SDL/sdl_lem_in3.c

INC		=	srcs/lem_in.h

OBJS	=	$(SRCS:.c=.o)

LIBS	=	libft/libft.a \
			printf/libftprintf.a \
			`SDL2-config --libs` \
			-lSDL2_ttf

CFLAGS	=	-Wall -Wextra -Werror `sdl2-config --cflags`

RM		=	rm -f

all		:	$(LIBS) $(NAME)

$(NAME)	:	$(OBJS) $(INC)
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBS)	:
	@$(MAKE) -C libft && $(MAKE) -C printf

clean	:
	$(RM) $(OBJS) && $(MAKE) clean -C libft && $(MAKE) clean -C printf

fclean	:	clean
	$(RM) $(NAME) libft/libft.a printf/libftprintf.a

re		:	fclean all
