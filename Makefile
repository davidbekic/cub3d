SRCS		= ./main.c

OBJS		= ${SRCS:.c=.o}

bold		= $(tput bold)

NAME		= cub3d

${NAME}:	${OBJS} 
			${CC}  -o ${NAME} ${LIBS} ${SRCS}
			@echo "\033[92m${bold}FDF COMPILED!\033[0m"

PRINTF		= ${OBJS} 

CC 		= cc
RM		= rm -f


LIBS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:		${NAME} 

clean: 		
		@echo "\033[91m${bold}CLEANING...\033[0m"
		${RM} ${OBJS} 

fclean:		clean
	
		${RM} ${NAME} 

			@echo "\033[92m${bol