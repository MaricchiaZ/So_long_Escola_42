NAME	= so_long #nome do executável

CC	= cc
INCLUDE		= -I ./ #  .h estará na pasta raiz
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE) # flags exigidas pela Escola 42
MLXFLAGS	= -lmlx -Ilmlx -lXext -lX11 # flags exigidas pela Escola 42 para o uso da mlx

RM	= rm -rf # para remover os .o e o ./so_long

PATH_SRCS	= ./ # scrs na pasta raiz
PATH_GNL	= $(PATH_SRCS)gnl/ # pasta gnl dentro da pasta raiz
PATH_UTILS	= $(PATH_SRCS)utils/ # pasta utils dentro da pasta raiz
PATH_OBJS	= $(PATH_SRCS)objs/  # pasta objs dentro da pasta raiz

SRCS	= ./main.c \ # arquivos da srs
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

OBJS	= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS)) # troca o caminho, e o .c por  .o

all:	$(NAME) # regra geral

$(NAME):	$(OBJS) # compila os arquivos usando as flags
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c # cria os objs da srcs na pasta objs, e as respectivas pastas
		@mkdir -p $(PATH_OBJS)
		@mkdir -p $(PATH_OBJS)gnl/
		@mkdir -p $(PATH_OBJS)utils/
		$(CC) $(CFLAGS) -c $< -o $@

clean: # remove a pasta c os objs
	$(RM) ./objs 

fclean: clean # remove o executável
	$(RM) $(NAME)

re:	fclean all # remove tudo E COMPILA TUDO DE NOVO  (isso salva sua vida)

.PHONY:	all $(PATH_OBJS) clean fclean re # impede o conflito quando há regra com mesmo nome de arquivo