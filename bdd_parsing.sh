TEMP_FILE="./minishell_commands.txt"
OUTPUT_FILE="./minishell_output.txt"


# Test 1 : User enters an invalid command line comprising two or more consecutive metacharacters

echo "Test: Invalid command with two or more consectuive metacharacters (ls ||| grep -a)"
echo "ls ||| grep a" > "$TEMP_FILE" # Écrit la commande dans le fichier
timeout 2 ./minishell < "$TEMP_FILE" > "$OUTPUT_FILE" 2>&1 # Limite à 2 secondes et redirige la sortie

# Vérifie si une erreur de syntaxe est retournée
if grep -q "invalid syntax" "$OUTPUT_FILE"; then
  echo "Test réussi : une erreur de syntaxe a été détectée"
else
  echo "Test échoué : pas d'erreur de syntaxe"
fi

# Test 2 : User enters a command with unbalanced quotes

echo "Test: Invalid command with unbalanced quotes"
echo "Hello \"unclosed" > "$TEMP_FILE"
timeout 2 ./minishell < "$TEMP_FILE" > "$OUTPUT_FILE" 2>&1

if grep -q "invalid syntax" 
