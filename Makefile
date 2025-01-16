# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:25:36 by sadoming          #+#    #+#              #
#    Updated: 2025/01/16 16:25:14 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D
BONUS		:=	cub3D_bonus

# Default map to run
MAP_DIR		:=	./assets/maps/
MAP_NAME	:=	$(MAP_DIR)other-map.cub

RUN_MAP_NAME:=	$(MAPS)$(MAP_NAME)
# ------------------ #
# Flags:

MAKF 		+=	--silent
MLX_FLAGS	:=	-B -DDEBUG=1

CC			=	gcc
CFLAGS		:=	-Wall -Werror -Wextra -g -c #-fsanitize=address
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

RG	:=	\033[1;32m
# ------------------ #
# Directories:

ASSETS_DIR	:=	./assets/
MAPS		:=	$(ASSETS_DIR)maps/

# SRC DIR
SRC_DIR		:=	./src/
INC_DIR		:=	$(SRC_DIR)inc
OBJ_DIR		:=	./obj

# BONUS DIR

BNS_DIR		:=	./bonus/
INCB_DIR	:=	$(BNS_DIR)inc
OBJB_DIR	:=	./objb
#-----

# libft DIR
LIB_DIR		:=	./libft
LIB_INC		:=	$(LIB_DIR)/inc
LIB_LIB		:=	$(LIB_DIR)/libft.a

# MLX42 DIR:
MLX_DIR		:=	./MLX42/
MLX_INC		:=	./MLX42/include/MLX42
MLX_LIB		:=	./MLX42/build/libmlx42.a
MLX_BUILD_DIR	:=	./MLX42/build/

# Sorces:
SRC_SRC	:=	cub_main.c man_memory.c check_file.c check_map.c\
			print_errors.c ft_print_map_t.c parse_info.c\
			start.c action.c raycasting.c raycollision.c\
			utilities.c collisions.c

SRC := $(addprefix $(SRC_DIR), $(SRC_SRC))

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.d, $(SRC))
-include $(DEPS)

## BONUS SRC
BNS_SRC	:=	cub_main_bonus.c man_memory_bonus.c check_file_bonus.c\
			check_map_bonus.c print_errors_bonus.c parse_info_bonus.c\
			start_bonus.c action_bonus.c raycasting_bonus.c\
			raycollision_bonus.c utilities_bonus.c collisions_bonus.c\
			paint_minimap_bonus.c bonus_actions_bonus.c

BNS := $(addprefix $(BNS_DIR), $(BNS_SRC))

OBJSB = $(patsubst $(BNS_DIR)%.c, $(OBJB_DIR)/%.o, $(BNS))
DEPSB = $(patsubst $(BNS_DIR)%.c, $(OBJB_DIR)/%.d, $(BNS))
-include $(DEPSB)

# More deps...
vpath %.h $(INC_DIR) $(INCB_DIR) $(MLX_INC) $(LIB_INC)
vpath %.c $(SRC_DIR) $(BNS_DIR)
vpath %.o $(OBJ_DIR) $(OBJB_DIR)
# ******************************************************************************* #
#-------------------------------------------------------------#
all: mlx42 $(LIB_LIB) $(NAME)
	@make -C $(LIB_DIR)
	@make -C $(MLX_BUILD_DIR) -j4
	@echo "$(RG)\n~ **************************************** ~\n"
	@echo "  ~\t     $(NAME) is ready!\t\t ~\n"
	@echo "~ **************************************** ~$(DEF)\n"
	@make -s author

# ----
mlx42:
	@echo "$(Y)Checking if MLX42 exist...$(DEF)"
	@if [ -d "MLX42" ]; then \
		echo "$(DEF)Dir exists, aborting cloning...\n"; \
	else \
		echo "$(B)Clonning ... $(DEF)"; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42; \
		cmake -B build; \
		cmake --build build -j4; \
	fi
#-------------------------------------------------------------#
author:
	@echo "$(P)~ **************************************** ~\n"
	@echo " ~\t      Made by Sadoming \t         ~"
	@echo " ~   With the collaboration of Andmart2  ~"
	@echo "~ **************************************** ~\n$(DEF)\n"
#-------------------------------------------------------------#
bonus: mlx42 $(LIB_LIB) $(BONUS)
	@make -C $(LIB_DIR)
	@make -C $(MLX_BUILD_DIR) -j4
	@echo "$(RG)\n~ **************************************** ~\n"
	@echo "  ~\t     $(BONUS) is ready!\t\t ~\n"
	@echo "~ **************************************** ~$(DEF)\n"
	@make -s author
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ \t\t\t #-> Make $(NAME)\n"
	@echo "\t~ all  \t\t #-> Make $(NAME)\n"
	@echo "\t~ bonus \t #-> Make $(BONUS)\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME)\n"
	@echo "\t~ run  \t\t #-> Run $(NAME)\n"
	@echo "\t~ run-bonus \t #-> Run $(BONUS)\n"
	@echo "\n If you're fancing problems with recompiling, try\n"
	@echo "\t remove-mlx\n And after `make all` or `make bonus`"
	@make -s author
#-------------------------------------------------------------#
norm:
	@echo "\n$(Y)~ Norminette:\n"
	@make -s norm -C $(LIB_DIR)
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(BNS_DIR)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette $(SRC_DIR) $(BNS_DIR)
	@echo "$(G)\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~$(DEF)\n"
#-------------------------------------------------------------#
run: all $(NAME)
	@echo "$(C)\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(RUN_MAP_NAME)"
	@echo "\n~ **************************************** ~ $(DEF)\n"
	@./$(NAME) $(RUN_MAP_NAME)
#-------------------------------------------------------------#
run-bonus: bonus $(BONUS)
	@echo "$(C)\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(RUN_MAP_NAME)"
	@echo "\n~ **************************************** ~ $(DEF)\n"
	@./$(BONUS) $(RUN_MAP_NAME)
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
$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(MAK) $(LIB_LIB) $(MLX_LIB)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_INC) -I $(LIB_INC) $(LIB_FLAGS) $< -o $@

#Cub3D
$(NAME): $(OBJS) $(LIB_LIB) $(MLX_LIB)
	@$(CC) $(OBJS) $(MLX_LIB) $(LIB_LIB) -o $(NAME) $(LIB_FLAGS)
	@echo "$(G)\n~ $(NAME) Compiled Successfully ~"
#-------------------------------------------------------------#

#Cub3D objs BONUS
$(OBJB_DIR)/%.o: $(BNS_DIR)%.c $(MAK) $(LIB_LIB) $(MLX_LIB)
	@mkdir -p $(OBJB_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_INC) -I $(LIB_INC) $(LIB_FLAGS) $< -o $@

#Cub3D BNS
$(BONUS): $(OBJSB) $(LIB_LIB) $(MLX_LIB)
	@$(CC) $(OBJSB) $(MLX_LIB) $(LIB_LIB) -o $(BONUS) $(LIB_FLAGS)
	@echo "$(G)\n~ $(BONUS) Compiled Successfully ~"
#-------------------------------------------------------------#
# ********************************************************************************* #
# Debug region

val: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) $(RUN_MAP_NAME)

val_s: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(RUN_MAP_NAME)

#-----------#
val-b: $(BONUS)
	@valgrind --leak-check=full --track-origins=yes ./$(BONUS) $(RUN_MAP_NAME)

val_s-b: $(BONUS)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(BONUS) $(RUN_MAP_NAME)

#-----------#
debug: re
	@echo "$(C)\n~ **************************************** ~\n"
	@echo " ~ lldb will launch ´./$(NAME) $(RUN_MAP_NAME)´"
	@echo "\n~ **************************************** ~ $(DEF)\n"
	@lldb $(NAME) $(RUN_MAP_NAME)

# ********************************************************************************* #
# Clean region

clean:
	@/bin/rm -frd $(OBJ_DIR)
	@/bin/rm -frd $(OBJB_DIR)
	@make -s clean -C $(LIB_DIR)
	@echo "$(B)\n All objs & deps removed$(DEF)\n"

fclean: clean
	@make -s fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@/bin/rm -f $(BONUS)
	@/bin/rm -frd $(BONUS).dSYM
	@echo "$(B)\n All cleaned succesfully$(DEF)\n"

clear: fclean
	@clear

remove-mlx: clear
	@rm -rf MLX42
	@echo "$(C)\tReady!$(DEF)\n"

re: fclean all
re-bonus: fclean bonus
# -------------------- #
.PHONY: all author clean fclean mlx42 norm re remove-mlx run val val_s
.PHONY: bonus re-bonus run-bonus val-b val_s-b
# ********************************************************************************** #
