#!/bin/bash


GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"

echo "TEST : LAUNCH MINISHELL"

# Lancer minishell en arrière-plan
mkfifo input_fifo

./minishell < input_fifo &
MINISHELL_PID=$!

# Attendre 5 secondes
sleep 5

# Vérifier si le processus est toujours en cours
if ps -p "$MINISHELL_PID" > /dev/null 2>&1; then
    echo -e "${GREEN}OK${RESET}"
    # Vous pouvez éventuellement ajouter d'autres vérifications ou actions ici
	rm input_fifo
	exit 0
else
    echo "${RED}KO${RESET}"
	rm input_fifo
    exit 1
fi
