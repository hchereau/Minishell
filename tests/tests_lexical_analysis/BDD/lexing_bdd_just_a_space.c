/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_bdd_just_a_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:58:32 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/18 17:00:05 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int		check_lexing_result(t_tokens_list lexer_output)
{
	if (lexer_output == NULL)
		return (EXIT_FAILURE);

	t_token_content	*first_token_content = (t_token_content *)lexer_output->content;
	t_token_content	*second_token_content = (t_token_content *)lexer_output->next->content;

	if (first_token_content->token_type != TOKEN_LIST_START)
		return (EXIT_FAILURE);
	if (second_token_content->token_type != TOKEN_LIST_END)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	test_input_just_a_space(void)
{
	//GIVEN

	char	*user_input = " ";

	//WHEN

	t_tokens_list	lexer_output = minishell_lexes_user_command_line(user_input);
	printf("%p\n", lexer_output);

	//THEN

	TEST_ASSERT_EQUAL(EXIT_SUCCESS, check_lexing_result(lexer_output));
}
/*

Test pour le lexer -> ici la fonction principale du lexer = build_token_list_from_user_input.

BUILD_TOKEN_LIST_FROM_USER_INPUT :

INPUT : une chaine de caracteres, correspondant a la ligne de commande saisie
		par l'utilisateur et envoyee au prompt.

OUTPUT : un pointeur sur une liste de tokens (t_token_list), corrspondant a l'entree de l'utilisateur
		decoupee en tokens.

GOAL : decouper et ordonner l'entree de l'utilisateur en lexems, afin de preter un
		sens a chaque entite qu'elle contient, pour quele shell puisse operer.

PROCESS :

*/
