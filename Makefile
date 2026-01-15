# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgervet <42@leogervet.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 10:49:16 by lgervet           #+#    #+#              #
#    Updated: 2026/01/15 14:34:07 by lgervet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Names ====
CLIENT          := client
SERVER          := server

# ==== Arguments ====
CC              := cc
CFLAGS          := -Wall -Wextra -Werror -g3
CPPFLAGS        := -Iincludes -Ilibft/includes
RM              := rm -f

# ==== Libft ====
LIBFT_DIR       := libft
LIBFT           := $(LIBFT_DIR)/libft.a

# ==== Sources Mandatory ====
SRCS_COMMON     := srcs/utils.c
SRCS_CLIENT     := srcs/client.c $(SRCS_COMMON)
SRCS_SERVER     := srcs/server.c $(SRCS_COMMON)
OBJS_CLIENT     := $(SRCS_CLIENT:.c=.o)
OBJS_SERVER     := $(SRCS_SERVER:.c=.o)

# ==== Sources Bonus ====
SRCS_COMMON_B   := srcs/utils_bonus.c
SRCS_CLIENT_B   := srcs/client_bonus.c $(SRCS_COMMON_B)
SRCS_SERVER_B   := srcs/server_bonus.c $(SRCS_COMMON_B)
OBJS_CLIENT_B   := $(SRCS_CLIENT_B:.c=.o)
OBJS_SERVER_B   := $(SRCS_SERVER_B:.c=.o)

# ==== Status Tags ====
#  Fichiers masqués qui empêchent le relink inutile
MANDATORY_DONE  := .mandatory_done
BONUS_DONE      := .bonus_done

# ==== Rules ====

.PHONY: all clean fclean re libft bonus

all:	$(MANDATORY_DONE)

# Règle Mandatory
$(MANDATORY_DONE): libft $(OBJS_CLIENT) $(OBJS_SERVER)
	@$(RM) $(BONUS_DONE)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER)
	@touch $(MANDATORY_DONE)

# Règle Bonus
bonus: $(BONUS_DONE)

$(BONUS_DONE): libft $(OBJS_CLIENT_B) $(OBJS_SERVER_B)
	@$(RM) $(MANDATORY_DONE)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_B) $(LIBFT) -o $(CLIENT)
	$(CC) $(CFLAGS) $(OBJS_SERVER_B) $(LIBFT) -o $(SERVER)
	@touch $(BONUS_DONE)

# Compilation de la Libft
libft:
	@$(MAKE) -C $(LIBFT_DIR)

# Compilation des objets
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Nettoyage
clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT_B) $(OBJS_SERVER_B)
	$(RM) $(MANDATORY_DONE) $(BONUS_DONE)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all