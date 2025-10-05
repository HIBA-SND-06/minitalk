NAME_SERVER	= server
NAME_CLIENT	= client

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_SERVER	= server.c
SRC_CLIENT	= client.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

# === Librairie === #
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I $(LIBFT_DIR)

# === Compilation === #

all: message $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(LIBFT_INC) -o $(NAME_SERVER)
	@echo "🟢 [$(NAME_SERVER)] compilé avec succès"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(LIBFT_INC) -o $(NAME_CLIENT)
	@echo "🟢 [$(NAME_CLIENT)] compilé avec succès"

message:
	@echo "========================================"
	@echo "           🛠️  Compilation             "
	@echo "         Projet: minitalk               "
	@echo "========================================"

# === Commandes Utiles === #

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "🧹 Fichiers objets supprimés"

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "🧨 Binaires supprimés"

re: fclean all

run: all
	@echo "🚀 Lancement du serveur en arrière-plan"
	@./$(NAME_SERVER)


.PHONY: all clean fclean re message