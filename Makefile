# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 10:29:47 by mal-moha          #+#    #+#              #
#    Updated: 2025/07/31 10:29:48 by mal-moha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

SRC_DIR		= .
OBJ_DIR		= obj
BONUS_DIR	= bonus
GNL_DIR		= $(BONUS_DIR)/get_next_line_bonus

SRCS		= main.c push_swap.c algorithm.c free_allocations.c initializations.c \
			  stack_operations.c push.c swap.c rotate.c reverse_rotate.c moves.c \
			  ft_split.c utils.c ft_printf.c helper.c

BONUS_SRCS	= $(BONUS_DIR)/checker_bonus.c \
			  $(BONUS_DIR)/checker_helper_bonus.c \
			  $(GNL_DIR)/get_next_line_bonus.c \
			  $(GNL_DIR)/get_next_line_utils_bonus.c \
			  initializations.c push.c swap.c rotate.c reverse_rotate.c \
			  ft_split.c utils.c ft_printf.c helper.c free_allocations.c stack_operations.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
