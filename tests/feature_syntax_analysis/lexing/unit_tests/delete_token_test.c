/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delte_token_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:17:46 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 21:17:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_delete_token(void)
{
	printf("Testing lexing: delete token\n");

	//ARRANGE
	t_token	*token_to_delete_1 = create_token("test", WORD);
	t_token	*token_to_delete_2 = create_token(">", INPUT_REDIR_OPERATOR);

	//ACT
	delete_token(&token_to_delete_1);
	delete_token(&token_to_delete_2);

	//ASSERT
	TEST_ASSERT_EQUAL(NULL, token_to_delete_1);
	TEST_ASSERT_EQUAL(NULL, token_to_delete_2);
}

/*

FONCTION "DELETE_TOKEN"

BUT: supprimer un token

INPUT: le token a supprimer
OUTPUT: none

PROCESS:

A/Efface le contenu du token -> FONCTION "ERASE_TOKEN_CONTENT"

B/Libere le token -> FREE

C/Met le token a NULL

*/
