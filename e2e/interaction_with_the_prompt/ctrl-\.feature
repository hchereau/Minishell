Feature: ctrl-\

	En tant que developpeur,
	je veux qu'en appuyant sur CTRL + \ rien ne se produise,
	afin de je sais pas mais c'est dans le sujet


	Scenario: User press ctrl-\ on the prompt
	Given I am a user and i'm at the Minishell prompt
	When I press ctrl and \ keys
	Then nothing happens
