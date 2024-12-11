import os
import time
import subprocess

FIFO_PATH = "/tmp/minishell_fifo"

def test_history():
    # Créer un FIFO si il n'existe pas déjà
    if not os.path.exists(FIFO_PATH):
        os.mkfifo(FIFO_PATH)

    # Lancer Minishell en arrière-plan (ne pas attendre la sortie)
    minishell_process = subprocess.Popen(["./minishell"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Attendre que minishell démarre
    time.sleep(1)

    # Simuler des entrées utilisateur dans le FIFO
    # Ouvrir le FIFO en écriture
    fifo_write = os.open(FIFO_PATH, os.O_WRONLY)

    # Envoyer des commandes à minishell
    os.write(fifo_write, b"test_command_1\n")
    time.sleep(0.5)  # Laisser le temps à minishell d'ajouter la commande à l'historique
    os.write(fifo_write, b"test_command_2\n")
    time.sleep(0.5)  # Laisser le temps à minishell d'ajouter la commande à l'historique

    # Fermer le FIFO après l'écriture
    os.close(fifo_write)

    # Attendre un peu pour que minishell puisse enregistrer les commandes
    time.sleep(1)

    # Lire depuis le FIFO (vérifier l'historique)
    fifo_read = os.open(FIFO_PATH, os.O_RDONLY)
    output = os.read(fifo_read, 1024).decode("utf-8").strip()
    os.close(fifo_read)

    # Vérifier que les commandes sont dans l'historique
    if "test_command_1" in output and "test_command_2" in output:
        print("Test réussi : L'historique fonctionne correctement.")
        return True
    else:
        print("Test échoué : L'historique ne contient pas les bonnes commandes.")
        return False

if __name__ == "__main__":
    if test_history():
        exit(0)
    else:
        exit(1)
