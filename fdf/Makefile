# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:26:10 by hasabir           #+#    #+#              #
#    Updated: 2022/06/27 17:17:35 by hasabir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OBJS = $(addprefix $(OBJ_D)/,main.o check_errors.o pipex_utils.o split.o pipex_utils_2.o pipex_utils_3.o)
# OBJ = obj
# OBJS = obj/main.o obj/check_errors.o obj/pipex_utils.o obj/split.o obj/pipex_utils_2.o obj/pipex_utils_3.o

NAME = fdf

# PATH = get_next_line

SRCS = main.c fdf_utils.c draw_map.c get_next_line.c get_next_line_utils.c\
	split.c draw_line.c mlx_utils.c display_map.c ft_atoi_base.c\
		
OBJ_D = obj

OBJS = $(addprefix $(OBJ_D)/,${SRCS:.c=.o}) 
# OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Imlx

all : ${NAME}

$(OBJ_D)/%.o: %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c -o $@ $<
# %.o: %.c 	# @$(CC) -c -o $@ $<

${NAME} :${OBJS}
	@$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

${OBJ_D} :
	@mkdir ${OBJ_D}
#	@mkdir ${PATH}/${OBJ_D}

clean:
	@rm -rf ${OBJ_D} 

fclean: clean
	@rm -rf ${NAME}

re: fclean all