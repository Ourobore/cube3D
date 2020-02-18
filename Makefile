RSRCS	=	./srcs

SRCS	=	$(RSRCS)/parsing/get_map_file.c \
			$(RSRCS)/parsing/parse_file.c \
			$(RSRCS)/parsing/map_validity.c \
			$(RSRCS)/parsing/get_next_line.c \
			$(RSRCS)/parsing/utils.c \
			$(RSRCS)/parsing/utils2.c \
			$(RSRCS)/parsing/error.c \
			$(RSRCS)/mlx/mlx.c \
			$(RSRCS)/mlx/images.c

OBJS	:=	${SRCS:.c=.o}

INCLUDE	=	-Icube3d.h

NAME	=	Cube3D

LIB		=	libcube3d.a

LIBFT	=	./libft/libft.a

FLAGS	=	-Wall -Werror -Wextra

.c.o:   
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make -C ./libft
			cp $(LIBFT) ./$(LIB)
			ar -rcs $(LIB) $(OBJS)
			gcc $(FLAGS) -g3 -fsanitize=address main.c $(LIB) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean	:	
			rm -rf $(OBJS)
			@make clean -C ./libft

fclean	:	clean
			rm -rf $(LIB) $(NAME)
			@make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re