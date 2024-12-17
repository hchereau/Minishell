/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:38:56 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 16:39:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_create_token(void)
{
	printf("Testing lexing: create_token\n");

	//ARRANGE
	char			*new_token_content = "Hello test";
	const t_token_type	new_token_type = WORD;
	t_token				*new_token;

	//ACT
	new_token = create_token(new_token_content, new_token_type);

	//ASSERT
	TEST_ASSERT_EQUAL(WORD, new_token->token_type);
	TEST_ASSERT_EQUAL(0, ft_strcmp(new_token_content, new_token->token_content));
	TEST_ASSERT_EQUAL(NULL, new_token->previous_token);
	TEST_ASSERT_EQUAL(NULL, new_token->next_token);
}

/*

FONCTION "CREATE_TOKEN"

BUT: creer un nouveau token, initialiser ses valeus (contenu + type)

INPUT: le contenu du token a creer (une chaine de caracteres) + son type.
OUTPUT: un pointeur intialise avec l'adresse de nouveau token.

PROCESS:

A/ Alloue l'espace necessaire pour le nouveau token (FONCTION -> MALLOC)

B/ Initialise le contenu de ce nouveau token en dupliquant la chaine de caracteres
qui lui est fournie en 1er argument (FONCTION -> FT_STRDUP)

C/ Initialise le type du nouveau token

D/ Met ses pointeurs previous et next a NULL

E/ RETURN l'adresse du nouveau token

*/
