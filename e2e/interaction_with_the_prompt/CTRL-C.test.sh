#!/bin/bash

#!/bin/bash

# Couleurs pour les messages
GREEN="\e[32m"
RED="\e[31m"
BLUE="\e[34m"
RESET="\e[0m"

echo "TEST : CTRL-C (SIGINT) IN MINISHELL"

# Créer un FIFO pour fournir l'entrée standard
FIFO_NAME="input_fifo"
mkfifo "$FIFO_NAME"

# Lancer minishell en arrière-plan avec le FIFO comme entrée
./minishell < "$FIFO_NAME" > output.txt 2>&1 &
MINISHELL_PID=$!

# Donner au minishell le temps de se lancer
sleep 2

# Envoyer Ctrl-C (SIGINT) au minishell
echo -e "${BLUE}Envoi de Ctrl-C (SIGINT) au processus minishell (PID: $MINISHELL_PID)${RESET}"
kill -SIGINT "$MINISHELL_PID"

# Attendre pour laisser le temps au minishell de réagir
sleep 2

# Vérifier si le minishell a imprimé un nouveau prompt après Ctrl-C
if grep -q "minishell>" output.txt; then
    echo -e "${GREEN}OK${RESET}"
    kill "$MINISHELL_PID"
    rm -f "$FIFO_NAME" output.txt
    exit 0
else
    echo -e "${RED}KO${RESET}"
    kill "$MINISHELL_PID"
    rm -f "$FIFO_NAME" output.txt
    exit 1
fi
