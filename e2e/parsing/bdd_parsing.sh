#!/bin/bash

# Variables pour le shell à tester
MINISHELL=../../minishell # Chemin vers votre exécutable
TEST_OUTPUT=/tmp/minishell_test_output

# Test une commande et compare le résultat
function test_command {
    local input="$1"
    local expected_output="$2"
    local expected_exit_code="$3"

    # Exécute la commande dans Minishell
    echo "$input" | $MINISHELL > $TEST_OUTPUT 2>&1
    local actual_exit_code=$?

    # Lire la sortie du shell
    local actual_output=$(cat $TEST_OUTPUT)

    # Comparer la sortie et le code de retour
    if [[ "$actual_output" == "$expected_output" && $actual_exit_code -eq $expected_exit_code ]]; then
        echo "✅ Test passed: '$input'"
    else
        echo "❌ Test failed: '$input'"
        echo "   Expected output: '$expected_output'"
        echo "   Actual output: '$actual_output'"
        echo "   Expected exit code: $expected_exit_code"
        echo "   Actual exit code: $actual_exit_code"
    fi
}

# Tests
test_command "echo Hello World" 0
test_command "echo >|" "Erreur syntaxique près de >|" 2
test_command "ls -l | | wc -l" "Erreur syntaxique près de | |" 2
test_command "cat < > file" "Erreur syntaxique près de < >" 2
