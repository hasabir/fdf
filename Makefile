# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:26:10 by hasabir           #+#    #+#              #
#    Updated: 2022/07/07 10:30:54 by hasabir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus

SRCS = main.c fdf_utils.c draw_map.c get_next_line.c get_next_line_utils.c\
	split.c draw_line.c mlx_utils.c display_map.c ft_atoi_base.c\
	fdf_utils_2.c fdf_utils_3.c

SRCS_BONUS = main_bonus.c fdf_utils.c draw_map.c get_next_line.c get_next_line_utils.c\
	split.c draw_line.c mlx_util_bonus.c display_map_bonus.c ft_atoi_base.c\
	fdf_utils_2.c fdf_utils_3.c
		
OBJ_D = obj
OBJ_B = obj_bonus

OBJS = $(addprefix $(OBJ_D)/,${SRCS:.c=.o})
OBJS_BONUS = $(addprefix $(OBJ_B)/,${SRCS_BONUS:.c=.o})

CC = gcc

CFLAGS = -Imlx

all : ${NAME}

$(OBJ_D)/%.o: %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :${OBJS}
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

${OBJ_D} :
	@mkdir ${OBJ_D}

bonus : ${BONUS}

$(OBJ_B)/%.o: %.c | ${OBJ_B}
	@$(CC) $(CFLAGS) -c -o $@ $<

${BONUS} :${OBJS_BONUS}
	@$(CC) $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

${OBJ_B} :
	@mkdir ${OBJ_B}


clean:
	@rm -rf ${OBJ_D} 
	@rm -rf ${OBJ_B} 

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${BONUS}

re: fclean all bonus