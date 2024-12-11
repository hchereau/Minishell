#!/bin/bash

echo "TEST : LAUNCH MINISHELL"

# Lancer minishell en arrière-plan
mkfifo input_fifo

./minishell < input_fifo &
MINISHELL_PID=$!

# Attendre 5 secondes
sleep 5

# Vérifier si le processus est toujours en cours
if ps -p "$MINISHELL_PID" > /dev/null 2>&1; then
    echo "OK"
    # Vous pouvez éventuellement ajouter d'autres vérifications ou actions ici
	exit 0
else
    echo "KO"
    exit 1
fi
