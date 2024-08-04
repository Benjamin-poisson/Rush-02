# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 10:40:15 by bepoisso          #+#    #+#              #
#    Updated: 2024/08/04 13:04:18 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
INC=include/*
EXEC=main

all: $(EXEC)

main:
	$(CC) main.c $(INC) $(CFLAGS)

fclean:
	rm -rf *.o *.out

debug:
	$(CC) debug.c $(INC) $(CFLAGS)
