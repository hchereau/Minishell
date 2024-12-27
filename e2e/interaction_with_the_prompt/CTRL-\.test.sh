#!/bin/bash

echo "TEST : CTRL-\\ (SIGQUIT) IN MINISHELL"

GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"

mkfifo myfifo

./minishell < myfifo &

sleep 2

MINISHELL_PID=$!

# Donne un peu de temps au minishell pour se lancer
sleep 2

# Vérifie si le processus existe avant d'envoyer SIGQUIT
if ps -p "$MINISHELL_PID" > /dev/null 2>&1; then
    echo "Minishell est en cours d'exécution."
else
    echo -e "${RED}Erreur : Minishell n'est pas en cours d'exécution.${RESET}"
    rm myfifo
    exit 1
fi

# Envoie SIGQUIT
echo "Envoi de SIGQUIT..."
kill -SIGQUIT "$MINISHELL_PID"

sleep 2


# Si le minishell est mort après le SIGQUIT, c'est KO
if ! ps -p "$MINISHELL_PID" > /dev/null 2>&1; then
    echo -e "${RED}KO${RESET}"
    rm myfifo
    exit 1
else
    # S'il est encore vivant, c'est OK
    echo -e "${GREEN}OK${RESET}"
    kill "$MINISHELL_PID"
    rm myfifo
    exit 0
fi


