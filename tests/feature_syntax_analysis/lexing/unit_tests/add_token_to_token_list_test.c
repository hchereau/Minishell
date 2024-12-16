/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_token_list_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	setUp(void)
{
	printf("testing lexing: add_token_to_token_list\n\n");
}

void	tearDown(void)
{
	printf('\n');
}

void	test_add_token_to_token_list(void)
{
	//ARRANGE
	t_token_list	token_list_test;
	t_token			*first_token = create_token("test 1", TOKEN_LIST_START);
	t_token			*second_token = create_token("test 2", TOKEN_LIST_END);

	token_list_test.token_list_first_token = NULL;

	//ACT
	add_token_to_token_list(&token_list_test, first_token);
	add_token_to_token_list(&token_list_test, second_token);

	//ASSERT
	TEST_ASSERT_EQUAL(token_list_test.token_list_first_token, first_token);
	TEST_ASSERT_EQUAL(token_list_test.token_list_first_token->next_token, second_token);
}

/*

FONCTION "ADD_TOKEN_TOKEN_LIST"

BUT: ajouter un token a la suite d'une liste de tokens

INPUT: un pointeur sur la liste, un pointeur sur le token a ajouter
OUTPUT: Une enum indiquant si l'ajout s'est bien passe

PROCESS:

A/ Parcourt la liste de tokens pour trouver le dernier. Si la liste est vide,
lui affecte le nouveau token puis se termine.

B/ Intialise le champ "previous token" du token ajoute avec l'adresse du dernier token

C/ Une fois sur le dernier token, intialise son champ "next_token" avec l'adresse
du token a ajouter.

*/
