# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:25:36 by sadoming          #+#    #+#              #
#    Updated: 2024/10/17 14:18:09 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

MAP_NAME	:=	level0.cub
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

COLOR_GREEN	:=	\033[0;32m
COLOR_RED	:=	\033[0;31m
COLOR_BLUE	:=	\033[0;34m
COLOR_END	:=	\033[0m
# ------------------ #
# Directories:

INC_DIR		:=	./inc
SRC_DIR		:=	./src/
OBJ_DIR		:=	./obj
BIN_DIR		:=	bin/
RES_DIR		:=	res/

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
vpath % $(BIN_DIR)
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
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "\n   ~ \t      Made by Sadoming \t        ~\n"
	@echo "\n~ **************************************** ~\n\n"
#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:\n"
	@norminette -R CheckForbiddenSourceHeader
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~\n"
#-------------------------------------------------------------#
run: all
	@./$(BIN_DIR)$(NAME) $(RES_DIR)$(RUN_MAP_NAME)
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
	@mkdir -p $(BIN_DIR)
	@$(CC) $(OBJS) $(MLX_LIB) $(LIB_LIB) -o $(BIN_DIR)$(NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(NAME)$(COLOR_END)"
#-------------------------------------------------------------#
# ********************************************************************************* #
# Debug region

val: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(BIN_DIR)$(NAME) $(RES_DIR)$(RUN_MAP_NAME)

val_s: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(BIN_DIR)$(NAME) $(RES_DIR)$(RUN_MAP_NAME)

# ********************************************************************************* #
# Clean region

clean:
	@/bin/rm -frd $(OBJ_DIR)
	@/bin/rm -frd ./bin
	@make -s clean -C $(LIB_DIR)
	@echo "\033[1;34m\n All objs & deps removed\033[1;97m\n"

fclean: clean
	@make -s fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean fclean re
# ********************************************************************************** #
