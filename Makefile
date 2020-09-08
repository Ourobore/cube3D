RSRCS	=	./srcs

SRCS	=	$(RSRCS)/parsing/get_map_file.c \
			$(RSRCS)/parsing/parse_file.c \
			$(RSRCS)/parsing/map_validity.c \
			$(RSRCS)/parsing/get_next_line.c \
			$(RSRCS)/parsing/utils.c \
			$(RSRCS)/parsing/utils2.c \
			$(RSRCS)/parsing/error.c \
			$(RSRCS)/parsing/save.c \
			$(RSRCS)/mlx/mlx.c \
			$(RSRCS)/mlx/raycasting.c \
			$(RSRCS)/mlx/player.c \
			$(RSRCS)/mlx/textures.c \
			$(RSRCS)/mlx/sprites.c \
			$(RSRCS)/mlx/controls.c \
			$(RSRCS)/mlx/bonus_controls.c \
			$(RSRCS)/mlx/free_struct.c \
			$(RSRCS)/mlx/utils.c

OBJS	:=	${SRCS:.c=.o}

INCLUDE	=	-Icube3d.h

NAME	=	Cube3D

LIB		=	libcube3d.a

LIBFT	=	./libft/libft.a

LIBMLX	=	./minilibx-linux/libmlx.a

#LIBMLX	=	./minilibx-opengl/libmlx.a

FLAGS	=	-Wall -Werror -Wextra

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make -C ./libft
			@make -C ./minilibx-linux
			#@make -C ./minilibx-opengl
			cp $(LIBFT) ./$(LIB)
			ar -rcs $(LIB) $(OBJS)
			gcc $(FLAGS) -g -D BONUS=0 main.c $(LIB) $(LIBMLX) -o $(NAME) -L$(LIBMLX) -lXext -lX11 -lm
			#gcc $(FLAGS) -g -D BONUS=0 main.c $(LIB) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

bonus	:	$(OBJS)
			@make -C ./libft
			@make -C ./minilibx-linux
			#@make -C ./minilibx-opengl
			cp $(LIBFT) ./$(LIB)
			ar -rcs $(LIB) $(OBJS)
			gcc $(FLAGS) -g -D BONUS=1 main.c $(LIB) $(LIBMLX) -o $(NAME) -L$(LIBMLX) -lXext -lX11 -lm
			#gcc $(FLAGS) -g -D BONUS=1 main.c $(LIB) -o $(NAME) -lmlx -framework OpenGL -framework AppKit



clean	:	
			rm -rf $(OBJS)
			@make clean -C ./libft
			@make clean -C ./minilibx-linux
			#@make clean -C ./minilibx-opengl

fclean	:	clean
			rm -rf $(LIB) $(NAME)
			@make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re
