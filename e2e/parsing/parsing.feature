feature: Syntax analysis
	As a developper
	I want my shell prompt to give me a syntax error on the input I just entered
	So that I can know if it is valid

Scenario: L'utilisateur entre une commande syntaxiquement invalide
	Given je tape une commande syntaxiquement invalide
	When j'appuie sur Entree
	Then j'ai une erreur de syntaxe sous la forme "minishell: parse
	error near `[NAME OF LEXEM]'"

Scenario: L'utilisateur entre une commande syntaxiquement valide
	Given je tape une commande syntaxiquement valide
	When j'appuie sur entree
	Then ma commande est prise en compte
