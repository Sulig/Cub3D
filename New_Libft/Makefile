# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 11:55:07 by sadoming          #+#    #+#              #
#    Updated: 2024/10/14 16:55:55 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
DEP_FLAGS = -MMD -MP
INCLUDE = -I $(INC_DIR)/
# ------------------ #
# Directories:

OBJ_DIR = ./obj
INC_DIR = ./inc

# Libft SRC Directories:
SRC_DIR = ./src/
IS_DIR 	= $(SRC_DIR)ft_is
GNL_DIR = $(SRC_DIR)ft_gnl
CNV_DIR = $(SRC_DIR)ft_cnv
MEM_DIR = $(SRC_DIR)ft_mem
STR_DIR = $(SRC_DIR)ft_str
WRT_DIR = $(SRC_DIR)ft_wrt
ARR_DIR = $(SRC_DIR)arrays
LST_DIR = $(SRC_DIR)ft_lst
# ------------------- #
# Sorces:
MAK = Makefile #This Makefile

# HEADERS:
HDR = $(INC_DIR)/

GNL_SRC = get_next_line.c get_next_line_utils.c
IS_SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_iscap.c ft_isdigit.c\
		ft_isnumeric.c ft_isprint.c
CNV_SRC = ft_atoi.c ft_atoi_base.c ft_itoa.c ft_strcapitalize.c ft_to_upplow.c
WRT_SRC = ft_printf.c ft_printf_fd.c ft_write_cast.c ft_write_cast_fd.c
MEM_SRC = ft_calloc.c ft_free.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		  ft_memmove.c ft_memset.c ft_memdup.c
STR_SRC = ft_split.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strcut.c\
		  ft_strinter.c ft_strjoin.c ft_strlen.c ft_strstr.c ft_strtrim.c\
		  ft_substr.c ft_apears_in.c ft_strremove.c

ARR_SRC = ft_arrmap.c ft_arrpop.c ft_arrpush.c ft_arrsize.c

LST_SRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c\
		  ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c\
		  ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c\
		  ft_lstnodepos_bonus.c

SRC := $(addprefix $(GNL_DIR)/, $(GNL_SRC))
SRC += $(addprefix $(IS_DIR)/, $(IS_SRC))
SRC += $(addprefix $(CNV_DIR)/, $(CNV_SRC))
SRC += $(addprefix $(MEM_DIR)/, $(MEM_SRC))
SRC += $(addprefix $(STR_DIR)/, $(STR_SRC))
SRC += $(addprefix $(WRT_DIR)/, $(WRT_SRC))
SRC += $(addprefix $(ARR_DIR)/, $(ARR_SRC))
SRC += $(addprefix $(LST_DIR)/, $(LST_SRC))

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.d, $(SRC))
-include $(DEPS)
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME)
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

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HDR) $(MAK)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(MAK) $(HDR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "\033[0;32m $(NAME) Compiled Successfully\033[0;37m\n"

# ********************************************************************************* #
# Clean region

clean:
	@/bin/rm -frd $(OBJ_DIR)
	@echo "\033[1;34m\n All objs & deps removed\033[1;97m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all author clean clear fclean help norm re
# ********************************************************************************** #
