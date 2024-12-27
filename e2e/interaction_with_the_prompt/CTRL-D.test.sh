#!/bin/bash

echo "TEST : CTRL-D IN MINISHELL"

GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"

# Créer un FIFO pour simuler l'entrée utilisateur
FIFO_NAME="input_fifo"
mkfifo "$FIFO_NAME"

# Lancer minishell en arrière-plan avec le FIFO comme entrée
./minishell < "$FIFO_NAME" &
MINISHELL_PID=$!

# Donner au minishell le temps de se lancer
sleep 2

# Simuler Ctrl-D en fermant le FIFO
exec 3>"$FIFO_NAME" && exec 3>&-

# Attendre quelques secondes pour permettre à minishell de traiter l'EOF
sleep 2

# Vérifier si le processus minishell est toujours en cours
if ps -p "$MINISHELL_PID" > /dev/null 2>&1; then
    echo -e "${RED}KO${RESET}"
    kill "$MINISHELL_PID"
	rm "$FIFO_NAME"
    exit 1
else
    echo -e "${GREEN}OK${RESET}"
	rm "$FIFO_NAME"
    exit 0
fi