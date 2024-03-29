TARGET_EXEC := cub3D

BUILD_DIR := ./build
SRC_DIRS := ./src
FSANITIZE := -fsanitize=address -g

NAME :=	$(TARGET_EXEC)

Y = "\033[33m"
G = "\033[32m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all:	$(NAME)

SRCS		= ./src/main.c \
				./src/events/ft_key_down.c \
				./src/init/ft_init_vars.c \
				./src/render/ft_cast_rays.c \
				./src/render/ft_render_frame.c \
				./src/render/ft_draw.c \
				./src/init/ft_init_img.c \
				./src/init/ft_init_textures.c \
				./src/init/ft_init_pos.c \
				./src/utils/ft_my_pixel_put.c \
				./src/utils/ft_key_check.c \
				./src/utils/ft_create_trgb.c \
				./src/utils/ft_my_pixel_get.c \
				./src/utils/ft_strdup.c \
				./src/movement/ft_move.c \
				./src/movement/ft_rotate.c \
				./src/parse/ft_parse_cub.c \
				./src/parse/ft_parse_map.c \
				./src/parse/ft_map_error_check.c \
				./src/parse/ft_parse_utils.c \
				./src/parse/ft_parse_color.c \
				./src/utils/get_next_line/get_next_line.c \
				./src/utils/get_next_line/get_next_line_utils.c \
				./src/utils/ft_is_digit.c \
				./src/utils/ft_calloc.c \
				./src/utils/ft_strcpy.c \
				./src/utils/ft_strlen.c \
				./src/utils/ft_strncmp.c \
				./src/exit/ft_exit.c

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
INC_FLAGS := -I./include

# LIBS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBMLX_DIR	=	mlx/
LIBMLX		=	$(addprefix $(LIBMLX_DIR), libmlx.a)
LNK			=	 -L $(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Wextra -Werror
#CFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Wextra -Werror $(FSANITIZE)

$(NAME): $(OBJS) $(LIBMLX)
	@echo $(Y)Linking...$(X)
	@$(CC) $(OBJS) ${LNK} -o $../$(NAME)
#	@$(CC) $(OBJS) ${LNK} -o $../$(NAME) $(FSANITIZE)
  	# @$(CC) $(OBJS) ${LNK} -o $../$(NAME) $(FSANITIZE)
	@printf $(UP)$(CUT)
	@echo $(G)COMPILED!$(X)

$(BUILD_DIR)/%.c.o: %.c
	@echo $(Y)Compiling [$<]...$(X) 
	@sleep 0.01
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $(UP)$(CUT)

$(LIBMLX): $(LIBMLX_DIR)/Makefile
	@echo $(Y)Building library...$(X)
	@$(MAKE) -C $(LIBMLX_DIR)

bonus:	$(NAME)

clean:
	@echo $(Y)Cleaning...$(X)
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@rm -rf $(BUILD_DIR)

fclean:		clean
	@echo $(Y)Removing binary...$(X)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean

-include $(DEPS)