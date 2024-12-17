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

	//ASSERT
	t_token	*token_to_delete = create_token("test", WORD);

	//ACT
	delete_token(token_to_delete);

	//ASSERT
	ASSERT_TEST_EQUAL(token_to_delete, NULL);
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
