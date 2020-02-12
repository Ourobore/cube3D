RSRCS	=	./srcs

SRCS	=	$(RSRCS)/get_map_file.c \
			$(RSRCS)/parse_file.c \
			$(RSRCS)/map_validity.c \
			$(RSRCS)/get_next_line.c \
			$(RSRCS)/utils.c \
			$(RSRCS)/utils2.c \
			$(RSRCS)/error.c

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
			gcc $(FLAGS) -g -fsanitize=address main.c $(LIB) -o $(NAME)

clean	:	
			rm -rf $(OBJS)
			@make clean -C ./libft

fclean	:	clean
			rm -rf $(LIB) $(NAME)
			@make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re