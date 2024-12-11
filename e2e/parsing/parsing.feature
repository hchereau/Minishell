feature: Syntax analysis
	As a developper
	I want my shell prompt to give me a syntax error on the input I just entered
	So that I can know if it is valid

	Scenario: User enters a valid single command pipeline
		Given I am a user and I'm at the Minishell prompt
		When I enter a valid single command such as "ls -l"
		And I press Enter
		Then no syntax error is returned

	Scenario: User enters a valid complex command pipeline
		Given I am a user and I'm at the Minishell prompt
		When I enter a valid complex command pipeline such as "ls -l | grep a > outfile"
		And I press Enter
		Then no syntax error is returned

	Scenario: User enters an invalid command line comprising two or more consecutive metacharacters
		Given I am a user and I'm at the Minishell prompt
		When I enter an invalid command line comprising two or more consecutive metacharacters (except for '>' or '<')
		And I press Enter
		Then a syntax error is returned

	Scenario: User enters an invalid command line comprising a metacharacter that unrecognized by the shell
		Given I am a user and I'm at the Minsihell prompt
		When I enter an invalid command line comprising a metacharacter that unrecognized by the shell (such as "&")
		And I press enter
		Then a syntax error is returned

Examples:
	| command					| result			|
	| ls -l						| no syntax error	|
	| echo "Hello"				| no syntax error	|
	| ech"o" yo					| no syntax error	|
	| ls -l | grep a > outfile	| no syntax error	|
	| << stop					| no syntax error	|
	| ls || grep a				| syntax error		|
	| echo a >>> outfile		| syntax error		|
	| echo a & ls				| syntax error		|
	| l"s						| syntax error		|














---------------------------------------------------------------------------------

NOTES POUR MOI MEME, MANUEL BASH, DEFINTIONS :

metacharacter:

 A character that, when unquoted, separates words.
 A metacharacter is:
 					a space,
					tab,
					newline,
or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.


Erreur notamment si :

					Deux metacaracteres autres que ">" ou "<" se suivent.
					Unclosed quotes.
					Un metacaractere pas reconnu par notre shell est present.
					= '&', ';', '(', ')'

