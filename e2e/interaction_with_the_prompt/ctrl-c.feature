Feature: CTRL-C

	En tant qu'utilisateur,
	je veux qu'en appuyant sur CTRL-C, mon prompt soit reinitialise,
	afin d'annuler mon entree en cours

  Scenario: User press ctrl-c on the prompt
	Given I am a user and i'm at the Minishell prompt
	When I press ctrl and c keys
	Then a new prompt is displayed on new line
	And the current command is cancelled (a symbol appear on the command line)
