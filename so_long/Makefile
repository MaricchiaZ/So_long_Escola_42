NAME	= so_long

CC	= cc
INCLUDE		= -I ./
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE)
MLXFLAGS	= -lmlx -Ilmlx -lXext -lX11

RM	= rm -rf

PATH_SRCS	= ./
PATH_GNL	= $(PATH_SRCS)gnl/
PATH_UTILS	= $(PATH_SRCS)utils/
PATH_OBJS	= ./objs/

SRCS	= ./main.c \
		./check.c \
		./check_2.c \
		./read.c \
		./game.c \
		./move.c \
		./window.c \
		./init.c \
		./valid_way.c \
		./clear_map.c \
		$(PATH_GNL)get_next_line.c \
		$(PATH_UTILS)ft_atoi.c \
		$(PATH_UTILS)ft_itoa.c \
		$(PATH_UTILS)ft_putstr.c \
		$(PATH_UTILS)ft_split.c \
		$(PATH_UTILS)ft_strchr.c \
		$(PATH_UTILS)ft_strdup.c \
		$(PATH_UTILS)ft_strjoin.c \
		$(PATH_UTILS)ft_strlcpy.c \
		$(PATH_UTILS)ft_strlen.c \
		$(PATH_UTILS)ft_substr.c \
		$(PATH_UTILS)ft_strstr.c \

OBJS	= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c
		@mkdir -p $(PATH_OBJS)
		@mkdir -p $(PATH_OBJS)gnl/
		@mkdir -p $(PATH_OBJS)utils/
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(PATH_OBJS) clean fclean re