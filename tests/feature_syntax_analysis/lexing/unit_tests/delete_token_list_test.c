/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_token_list_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:14:36 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 21:14:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_delete_token_list(void)
{
	printf("Testing lexing: delete_token_list\n");

	//ARRANGE

	t_token_list	token_list_test;
	ft_bzero(&token_list_test, sizeof(t_token_list));
	t_token			*token_test_1 = create_token("test_1", TOKEN_LIST_START);
	t_token			*token_test_2 = create_token("test 2", WORD);
	t_token			*token_test_3 = create_token("test 3", TOKEN_LIST_END);

	add_token_to_token_list(&token_list_test, token_test_1);
	add_token_to_token_list(&token_list_test, token_test_2);
	add_token_to_token_list(&token_list_test, token_test_3);

	print_token_list(token_list_test);
	//ACT

	delete_token_list(&token_list_test);

	//ASSERT

	TEST_ASSERT_EQUAL(NULL, token_list_test.token_list_first_token);
	TEST_ASSERT_EQUAL(NULL, token_list_test.token_list_last_token);
	TEST_ASSERT_EQUAL(NULL, token_list_test.token_list_first_token);
}

/*

FONCTION "DELETE TOKEN LIST"

BUT: supprimer une liste de tokens.

INPUT: la liste de tokens a supprimer
OUTPUT: none

PROCESS:

A/ Parcourt la liste de tokens, applique sur chacun la fonction "DELETE TOKEN".

B/ Une fois l'operation terminee, met la lsite a NULL.

*/
