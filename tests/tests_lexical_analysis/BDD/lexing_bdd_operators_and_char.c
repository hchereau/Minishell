/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_bdd_operators_and_char.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:54:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/21 17:55:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_input_operators_and_one_char(void)
{
	//ARRANGE

	t_token_type	token_1 = TOKEN_LIST_START;
	t_token_type	token_2 = PIPE_OPERATOR;
	t_token_type	token_3 = INPUT_REDIR_OPERATOR;
	t_token_type	token_4 = OUTPUT_REDIR_OPERATOR;
	t_token_type	token_5 = WORD;
	t_token_type	token_6 = TOKEN_LIST_END;

	char	*user_input = "|<>a";

	//WHEN

	t_token_list	lexer_output = tokenize(user_input);

	//THEN

	t_token_list	current;

	current = lexer_output;
	TEST_ASSERT_EQUAL(6, ft_lstsize(lexer_output));
	TEST_ASSERT_EQUAL(token_1, ((t_token *)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_2, ((t_token*)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_3, ((t_token*)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_4, ((t_token*)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_5, ((t_token*)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_6, ((t_token*)current->content)->token_type);
	// TEST_AEERT_EQUAL(0, ft_strcmp(current->content.))

	//to_print

	print_token_list(lexer_output);

	//to_clear
}
