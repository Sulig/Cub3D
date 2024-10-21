# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:25:36 by sadoming          #+#    #+#              #
#    Updated: 2024/10/21 14:06:46 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

MAP_NAME	:=	example-map1.cub
RUN_MAP_NAME:=	$(MAPS)$(MAP_NAME)
# ------------------ #
# Flags:

MAKF 		+=	--silent
MLX_FLAGS	:=	-B

CC			= gcc
CFLAGS		:=	-Wall -Werror -Wextra -g -c
LIB_FLAGS	:=	-lm -ldl -lglfw -pthread

DEP_FLAGS	:= -MMD -MP
# ------------------ #
# Colors

R	:=	\033[0;31m
G	:=	\033[0;32m
Y	:=	\033[0;33m
B	:=	\033[0;34m
P	:=	\033[0;35m
C	:=	\033[0;36m
W	:=	\033[0;37m
DEF	:=	\033[0m
# ------------------ #
# Directories:

INC_DIR		:=	./inc
SRC_DIR		:=	./src/
OBJ_DIR		:=	./obj

ASSETS_DIR	:=	./assets/
MAPS		:=	$(ASSETS_DIR)maps/

LIB_DIR		:=	./New_Libft
LIB_INC		:=	./New_Libft/inc
LIB_LIB		:=	./New_Libft/libft.a

MLX_DIR		:=	./MLX42/
MLX_INC		:=	./MLX42/include/MLX42
MLX_LIB		:=	./MLX42/build/libmlx42.a
MLX_BUILD_DIR	:=	./MLX42/build/
# ------------------ #
# Sorces:

SRC_SRC	:=	cub_main.c

SRC := $(addprefix ./src/, $(SRC_SRC))

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.d, $(SRC))
-include $(DEPS)

vpath %.h $(INC_DIR) $(MLX_INC) $(LIB_INC)
vpath %.c $(SRC_DIR) $(TST_DIR) $(_DM_DIR) $(_MM_DIR) $(_BG_DIR) $(_UT_DIR) $(_PL_DIR) $(_RC_DIR) $(_WALL_DIR) $(_PIX_DIR)
vpath %.o $(OBJ_DIR)
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME) $(LIB_LIB) $(MLX_LIB)
	@make -C $(LIB_DIR)
	@make -C $(MLX_BUILD_DIR) -j4
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ \t\t\t #-> Make $(NAME)\n"
	@echo "\t~ all  \t\t #-> Make $(NAME)\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME)\n"
	@make -s author

#-------------------------------------------------------------#
author:
	@echo "$(P)\n~ **************************************** ~\n"
	@echo "   ~ \t      Made by Sadoming \t        ~"
	@echo "\n~ **************************************** ~\n$(DEF)\n"
#-------------------------------------------------------------#
norm:
	@echo "\n$(Y)~ Norminette:\n"
	@make -s norm -C $(LIBFT)
	@norminette -R CheckForbiddenSourceHeader $(INC_DIR) $(SRC_DIR)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette $(INC_DIR) $(SRC_DIR)
	@echo "$(G)\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~$(DEF)\n"
#-------------------------------------------------------------#
run: $(NAME)
	@echo "$(C)\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(RUN_MAP_NAME)"
	@echo "\n~ **************************************** $(DEF)~\n"
	@./$(NAME) $(RUN_MAP_NAME)
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

#Libft
$(LIB_LIB):
	@make -C $(LIB_DIR)

#MLX Codam
$(MLX_LIB):
	@cmake $(MLX_DIR) $(MLX_FLAGS) $(MLX_BUILD_DIR)
	@make -C $(MLX_BUILD_DIR) -j4

#-------------------------------------------------------------#
#Cub3D objs
$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HDRS) $(MAK) $(LIB_LIB) $(MLX_LIB)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_INC) -I $(LIB_INC) $(LIB_FLAGS) $< -o $@
	@echo "$(COLOR_GREEN)write file: $(OBJ_DIR)$@ $(COLOR_END)"

#Cub3D
$(NAME): $(OBJS) $(LIB_LIB) $(MLX_LIB)
	@$(CC) $(OBJS) $(MLX_LIB) $(LIB_LIB) -o $(NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(NAME)$(COLOR_END)"
#-------------------------------------------------------------#
# ********************************************************************************* #
# Debug region

val: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) $(RUN_MAP_NAME)

val_s: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(RUN_MAP_NAME)

# ********************************************************************************* #
# Clean region

clean:
	@/bin/rm -frd $(OBJ_DIR)
	@make -s clean -C $(LIB_DIR)
	@echo "$(B)\n All objs & deps removed$(DEF)\n"

fclean: clean
	@make -s fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@echo "$(B)\n All cleaned succesfully$(DEF)\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean fclean re
# ********************************************************************************** #
