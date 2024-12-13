cd "$(dirname "$0")"

TEMP_FILE="minishell_commands.txt"
OUTPUT_FILE="minishell_output.txt"
MINISHELL_EXEC="../../minishell"

#echo "Répertoire courant : $(pwd)"

# Test 1 : User enters an invalid command line

echo "Test 1: Invalid command (ls ||| grep -a)"
echo "ls ||| grep a" > "$TEMP_FILE" # Écrit la commande dans le fichier
timeout 2 "$MINISHELL_EXEC" < "$TEMP_FILE" > "$OUTPUT_FILE" 2>&1

# Vérifie si une erreur de syntaxe est retournée
if grep -q "invalid syntax" "$OUTPUT_FILE"; then
  echo "Test réussi : une erreur de syntaxe a été détectée"
else
  echo "Test échoué : pas d'erreur de syntaxe"
fi

# Test 2 : User enters a command with unbalanced quotes

echo "Test 2: Invalid command (Hello \"unclosed)"
echo "Hello \"unclosed" > "$TEMP_FILE"
timeout 2 "$MINISHELL_EXEC" < "$TEMP_FILE" > "$OUTPUT_FILE" 2>&1

if grep -q "invalid syntax" "$OUTPUT_FILE"; then
  echo "Test réussi : une erreur de syntaxe a été détectée"
else
  echo "Test échoué : pas d'erreur de syntaxe"
fi
