/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_bdd_pipe_and_redir.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:23:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/20 17:23:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_input_pipe_and_input_redir(void)
{
	//ARRANGE

	t_token_type	token_1 = TOKEN_LIST_START;
	t_token_type	token_2 = PIPE_OPERATOR;
	t_token_type	token_3 = INPUT_REDIR_OPERATOR;
	t_token_type	token_4 = TOKEN_LIST_END;

	char	*user_input = "|<";

	//WHEN

	t_token_list	lexer_output = tokenize(user_input);

	//THEN

	t_token_list	current;

	current = lexer_output;
	TEST_ASSERT_EQUAL(4, ft_lstsize(lexer_output));
	TEST_ASSERT_EQUAL(token_1, ((t_token *)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_2, ((t_token*)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_3, ((t_token*)current->content)->token_type);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_4, ((t_token*)current->content)->token_type);

	//to_print

	print_token_list(lexer_output);

	//to_clear

	delete_token_list(lexer_output);
}
