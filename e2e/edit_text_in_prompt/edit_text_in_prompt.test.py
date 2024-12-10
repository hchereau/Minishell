import pexpect

# Lancer Minishell
child = pexpect.spawn('./minishell')

# Vérifier que le prompt s'affiche
child.expect("SDF> ")

# Envoyer une commande
child.sendline("echo Hello World")

# Lire la sortie et vérifier
child.expect("Hello World")
print("Test passed: 'echo Hello World' executed correctly.")

# Quitter le shell
child.sendcontrol('d')
child.expect(pexpect.EOF)
