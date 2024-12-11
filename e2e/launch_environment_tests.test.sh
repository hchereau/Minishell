#!/bin/bash

# Définir les répertoires contenant les scripts
DIR1="e2e/Launch_shell"
DIR2="e2e/interaction_with_the_prompt"

# Couleurs pour les messages
GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"
BLUE="\e[34m"

# Variable pour suivre l'état global des tests
GLOBAL_STATUS=0

echo "Lancement de tous les scripts shell dans les répertoires :"
echo "1. $DIR1"
echo "2. $DIR2"

# Fonction pour exécuter les scripts d'un répertoire donné
execute_scripts_in_dir() {
    local dir="$1"
    if [[ -d "$dir" ]]; then
        for script in "$dir"/*.sh; do
            if [[ -x "$script" ]]; then
                echo -e "${BLUE}Exécution du script : $script${RESET}"
                bash "$script"
                SCRIPT_STATUS=$?

                if [[ $SCRIPT_STATUS -ne 0 ]]; then
                    echo -e "${RED}Échec du script : $script${RESET}\n"
                    GLOBAL_STATUS=1
                else
                    echo -e "${GREEN}Succès du script : $script${RESET}\n"
                fi
            else
                echo -e "${RED}Le fichier $script n'est pas exécutable. Passer au suivant.${RESET}\n"
                GLOBAL_STATUS=1
            fi
        done
    else
        echo -e "${RED}Le répertoire $dir n'existe pas.${RESET}\n"
        GLOBAL_STATUS=1
    fi
}

# Exécuter les scripts dans chaque répertoire
execute_scripts_in_dir "$DIR1"
execute_scripts_in_dir "$DIR2"

# Retourner le code d'erreur global
if [[ $GLOBAL_STATUS -ne 0 ]]; then
    echo -e "${RED}Des tests ont échoué.${RESET}"
else
    echo -e "${GREEN}Tous les tests ont réussi.${RESET}"
fi

exit $GLOBAL_STATUS

