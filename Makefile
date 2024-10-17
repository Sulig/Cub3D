# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:25:36 by sadoming          #+#    #+#              #
#    Updated: 2024/10/16 19:22:36 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
# ------------------ #
# Flags:

CC = gcc
CFLAGS := -Wall -Wextra -Werror -g #-fsanitize=address # -Wunreachable-code -Ofast
LIB_FLAGS	:=	-lm -ldl -lglfw -pthread
DEP_FLAGS	:= -MMD -MP
HEADERS		:= -I ./inc -I $(LIBMLX)/include -I $(LIB_DIR)/inc
FML			:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX_FLAGS	:= -B
DEBUG_F		= -DDEBUG=1
# ------------------ #
# Directories:

MLX_DIR			= ./MLX42 #MLX of Codam
MLX_BUILD_DIR	:= ./MLX42/build/
LIB_DIR	= ./New_Libft #My Libft

LIBS	:= ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

OBJ_DIR = ./obj
INC_DIR = ./inc

# SRC Directories:
SRC_DIR = ./src

# ------------------- #
# Sorces:
MAK = Makefile #This Makefile

ARL = ./New_Libft/libft.a
MLX_LIB	:=	./MLX42/build/libmlx42.a

HDR = $(INC_DIR)/

SRC_SRC = cub_main.c

SRC := $(addprefix ./src/, $(SRC_SRC))

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.d, $(SRC))
-include $(DEPS)
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME) $(ARL) #$(MLX_LIB)
#-------------------------------------------------------------#
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
#-------------------------------------------------------------#
author:
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "\n   ~ \t      Made by Sadoming \t        ~\n"
	@echo "\n~ **************************************** ~\n\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:\n"
	@norminette -R CheckForbiddenSourceHeader
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

#Libft
$(ARL):
	@echo "\033[0;93m\n * Compiling Libft -->\033[1;97m\n"
	@make -C $(LIB_DIR)
	@echo "\033[0;37m\n~ **************************************** ~\n"

#MLX Codam
$(MLX_LIB):
	@cmake $(MLX_DIR) $(MLX_FLAGS) $(MLX_BUILD_DIR)
	@make -C $(MLX_BUILD_DIR) -j4

#-------------------------------------------------------------#
#Cub3D objs
$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(MAK) $(HDR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEP_FLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)"

#Cub3D
$(NAME): $(MAK) $(ARL) $(OBJ) $(HDR)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(NAME) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t     $(NAME) is ready!\t\t ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#

# ********************************************************************************* #
# Clean region

clean:
	@/bin/rm -frd $(OBJ_DIR)
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
.PHONY: all author clean clear fclean help norm re libmlx00
# ********************************************************************************** #
