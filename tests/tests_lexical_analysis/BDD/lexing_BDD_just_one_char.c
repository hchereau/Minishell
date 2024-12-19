/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_BDD_just_one_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:23:36 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/19 19:24:46 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_input_just_one_letter(void)
{
	//ARRANGE

	t_token_type	token_1 = TOKEN_LIST_START;
	t_token_type	token_2 = WORD;
	t_token_type	token_3 = TOKEN_LIST_END;

	char	*user_input = "a";

	//WHEN

	t_token_list	lexer_output = minishell_lexes_user_command_line(user_input);
	printf("%p\n", lexer_output);

	//THEN

	t_token_list	current;

	current = lexer_output;
	TEST_ASSERT_EQUAL(3, ft_lstsize(lexer_output));
	TEST_ASSERT_EQUAL(EXIT_SUCCESS, check_lexing_result(lexer_output));
	TEST_ASSERT_EQUAL(token_1, (t_token*)current->content);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_2, (t_token*)current->content);
	current = (t_token_list)current->next;
	TEST_ASSERT_EQUAL(token_3, (t_token*)current->content);

	//to_print

	//to_clear
}
