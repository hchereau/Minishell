/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple_command_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:45:54 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/13 21:54:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	set_tokens_values(t_token *fst_token, t_token *scnd_token,
				t_token *lst_token)
{
	fst_token->token_type = ENTRY_START;
	scnd_token->token_type = WORD;
	lst_token->token_type = ENTRY_END;
	fst_token->next_token = scnd_token;
	scnd_token->next_token = lst_token;
	lst_token->next_token = NULL;
}

void	setUp(void)
{
	printf("testing parsing: simple command / no args\n");
}

void	tearDown(void)
{

}

void	test_simple_command_no_options_valid(void)
{
	t_token_list		tokenized_input;
	t_token				first_token;
	t_token				second_token;
	t_token				last_token;
	t_syntax_verified	parser_output;

	//ARRANGE
	set_tokens_values(&first_token, &second_token, &last_token);
	tokenized_input.entry_start = &first_token;

	//ACT
	parser_output = syntax_analyser(tokenized_input);

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


cw -Iincludes -IUnity/src -Ilibft/includes tests/tests_main.c tests/feature_syntax_analysis/parsing/parsing_bdd.c tests/feature_syntax_analysis/parsing/test_simple_command_valid.c srcs/syntax_analysis/parsing/syntax_analyser.c Unity/src/unity.c -fsanitize=address -g3

*/
