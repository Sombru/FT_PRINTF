# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 15:29:51 by pkostura          #+#    #+#              #
#    Updated: 2023/11/21 16:46:26 by pkostura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= libftprintf.a
AR		= ar rcs
CFLAGS 	= -Wall -Werror -Wextra $(LIB)
CC 		= cc
RM 		= rm -rf
SRC		= src/ft_formats.c src/ft_printf.c
INC 	= inc/

LIB  	= -I$(INC)
OBJS 	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS) 

clean:
	@rm -f test a.out $(OBJS) 
	
fclean: clean
	@rm -f test a.out $(NAME)

test:
	@cc $(CFLAGS) -o test src/*.c
	
re: fclean all

