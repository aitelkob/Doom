# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 05:22:43 by aeddaqqa          #+#    #+#              #
#    Updated: 2020/12/30 09:15:58 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Doom

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SDLF = -I SDL/SDL2.framework/Headers   

INC = includes/headers.h

SRC = srcs/main.c srcs/algebr_lin/vect3_utilfun.c srcs/algebr_lin/vect3_utilfunc.c\
srcs/render/main_render.c srcs/setup/main_setup.c srcs/update/main_update.c\
srcs/update/main_input.c srcs/update/find_intersection.c srcs/render/draw_2Dmap.c

FRAM =  -framework SDL2 -F ./SDL/ -framework SDL2_mixer -F ./SDL  -framework SDL2_image -F ./SDL -rpath @loader_path/SDL -lz

OBJ = $(SRC:.c=.o) 

F_OBJ = ./OBJ

all: $(NAME) 
$(NAME):$(OBJ)$(INC)
		@echo "\033[2;36m"
		@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(FRAM)  $(SDLF) -o $(NAME)
		@echo "Doom_Nukem_3D: executable file is ready"
		@echo "\033[0m"
clean:
		@echo "\033[2;32m"
		@rm -rf $(OBJ)   2> /dev/null || true
		@echo "Doom_Nukem_3D: all resources deleted"
		@echo "\033[0m"
fclean: clean 
		@echo "\033[2;34m"
		@rm -f $(NAME)  2> /dev/null || true
		@echo "Doom_Nukem_3D: all resources deleted"
		@echo "\033[0m"
		
re: fclean all
