# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgervet <42@leogervet.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 10:49:16 by lgervet           #+#    #+#              #
#    Updated: 2025/12/23 14:21:07 by lgervet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Names ====
CLIENT  := client
SERVER  := server

# ==== Tooling ====
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3
CPPFLAGS:= -Iincludes -Ilibft/includes

RM      := rm -f

# ==== Libft ====
LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a

# ==== Sources ====
SRCS_COMMON := srcs/utils.c
SRCS_CLIENT := srcs/client.c $(SRCS_COMMON)
SRCS_SERVER := srcs/server.c $(SRCS_COMMON)

OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)
OBJS_SERVER := $(SRCS_SERVER:.c=.o)

.PHONY: all clean fclean re libft test

all: libft $(CLIENT) $(SERVER)

# Build libft once
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Link client/server with libft
$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $@

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $@

# Compile objects
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# Optionnel: build un binaire de test séparé
test: libft tests/test.c srcs/utils.c
	$(CC) $(CFLAGS) $(CPPFLAGS) tests/test.c srcs/utils.c $(LIBFT) -o test_minitalk
