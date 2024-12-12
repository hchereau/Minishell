#!/bin/bash

# Couleurs pour les messages
GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"

echo "TEST : Vérification du comportement de Ctrl-C dans minishell"

# Fichier temporaire pour capturer la sortie de minishell
OUTPUT_FILE="output.txt"

touch "$OUTPUT_FILE"

# Commande pour lancer minishell et simuler Ctrl-C
# Utilisation de script pour exécuter une session interactive
script -q -c "./minishell" $OUTPUT_FILE 2>&1 &
MINISHELL_PID=$!

# Attendre que minishell soit prêt
sleep 2

# Envoyer Ctrl-C au processus minishell
echo -e "Envoi de Ctrl-C (SIGINT) au processus minishell (PID: $MINISHELL_PID)"
kill -SIGINT "$MINISHELL_PID"

# Attendre pour laisser le temps à minishell de réagir
sleep 2

# Arrêter le processus minishell proprement s'il est toujours en cours
kill "$MINISHELL_PID" 2>/dev/null

# Vérifier si le prompt apparaît dans le fichier de sortie après Ctrl-C
if grep -q "SDF$> " "$OUTPUT_FILE"; then
    echo -e "${GREEN}OK${RESET}"
    rm -f "$OUTPUT_FILE"
    exit 0
else
    echo -e "${RED}KO${RESET}"
    rm -f "$OUTPUT_FILE"
    exit 1
fi
