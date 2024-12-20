/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:23:56 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/20 17:24:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	second_test_with_a_pipe(void)
{
	//ARRANGE

	t_token	token_test;
	t_token	*token_to_create;

	token_test.token_lexem = NULL;
	token_test.token_type = PIPE;

	//ACT

	token_to_create = create_token(NULL, PIPE);

	//ASSERT

	TEST_ASSERT_EQUAL(token_test.token_lexem, token_to_create->token_lexem);
	TEST_ASSERT_EQUAL(token_test.token_type, token_to_create->token_type);
}

static void	first_test_with_a_word(void)
{
	//ARRANGE

	t_token	token_test;
	t_token	*token_to_create;

	token_test.token_lexem = "Hello";
	token_test.token_type = WORD;

	//ACT

	token_to_create = create_token("Hello", WORD);

	//ASSERT

	TEST_ASSERT_EQUAL(token_test.token_lexem, token_to_create->token_lexem);
	TEST_ASSERT_EQUAL(token_test.token_type, token_to_create->token_type);
}

void	test_create_token(void)
{
	first_test_with_a_word();
	second_test_with_a_pipe();
}
