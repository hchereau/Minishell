/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple_command_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:45:54 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/13 18:31:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	arrange(t_token_type first_value, t_token_type second_value,
				t_token *first_token, t_token *second_token)
{
	first_token->token_type = first_value;
	first_token->next_token = second_token;
	second_token->token_type = second_value;
	second_token->next_token = NULL;
}

void	set_up(void)
{

}

void	tear_down(void)
{

}

void	test_simple_command_valid(t_token_type first_token_value,
			t_token_type second_token_value)
{
	t_token				first_token;
	t_token				second_token;
	t_syntax_verified	parser_output;

	//ARRANGE
	arrange(first_token_value, second_token_value, &first_token, &second_token);

	//ACT
	parser_output = minishell_syntax_analyser(&first_token);

	//ASSERT
	TEST_ASSERT_EQUAL(VALID_SYNTAX, parser_output);
}


/*

IMPORTANT:

-> Ici l'idee c'est de tester comment le parser reagit a differentes suites de
   tokens ! Pour voir si il identifie bien les suites logiques et valides,
   ou illogiques et invalides entre les tokens qu'on lui presente.

   Pour savoir si un token est correctement forme, et savoir si les donnees qu'il
   contient sont correctement remplies, et correspondent bien a son type, son
   contenu, etc ... il faut se referer aux tests unitaires qui seront effectues
   sur le module de lexing.


---------------------------------------------------------------------------------

MODULE PARSING =

1/ Le lexer :

INPUT = une chaine de caracteres (constante ?), l'input de l'utilisateur.
OUTPUT = une liste ordonnee de tokens --> (dans le but de la fournir au PARSER)

GOAL = decouper la ligne de commande entree par l'utilisateur en une suite de lexem
		(suite d'entites comprises dans le lexique du shell)

PROCESS =


2/ L'analyseur de syntaxe :

INPUT = une suite de lexems (voir structure de donnees, surement une liste chainee)
OUTPUT = une enum indiquant si cette suite de lexems respecte la syntaxe du shell

GOAL = definir si la suite de tokens qui lui est fourni respecte la syntaxe du shell

PROCESS =

*/
