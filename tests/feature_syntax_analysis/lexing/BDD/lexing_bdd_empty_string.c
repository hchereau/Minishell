/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_bdd_empty_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:58:32 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:28:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int		check_lexing_result(t_token_list lexer_output)
{
	t_token_type	expected_output[] = {TOKEN_LIST_START, WORD, TOKEN_LIST_END};
	size_t			expected_output_size;
	size_t			i;
	t_token			*current_token;

	i = 0;
	current_token = lexer_output.token_list_first_token;
	expected_output_size = 3;
	while (current_token != NULL && i < expected_output_size)
	{
		if (expected_output[i] != current_token->token_type)
			return (FAILURE);
		current_token = current_token->next_token;
		++i;
	}
	if (i != expected_output_size || current_token != NULL)
		return (FAILURE);
	return (SUCCESS);
}

void	test_input_empty_string(void)
{
	t_token_list	lexer_output;

	//ARRANGE
	char			*user_input = "";

	//ACT
	lexer_output = build_token_list_from_user_input(user_input);

	//ASSERT
	TEST_ASSERT_EQUAL(SUCCESS, check_lexing_result(lexer_output));
}
/*

Test pour le lexer -> ici la fonction principale du lexer = build_token_list_from_user_input.

BUILD_TOKEN_LIST_FROM_USER_INPUT :

INPUT : une chaine de caracteres, correspondant a la ligne de commande saisie
		par l'utilisateur et envoyee au prompt.

OUTPUT : une liste de tokens (t_token_list), corrspondant a l'entree de l'utilisateur
		decoupee en lexems.

GOAL : decouper et ordonner l'entree de l'utilisateur en lexems, afin de preter un
		sens a chaque entite qu'elle contient, pour quele shell puisse operer.

PROCESS :

*/
