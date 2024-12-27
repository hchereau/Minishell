/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_bdd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:12:54 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 17:57:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	lexing_bdd_tests(void)
{
	printf("\nTOKEN LISTE TEST EMPTY:\n\n");
	test_input_just_a_space();
	printf("\nTOKEN LISTE TEST PIPE:\n\n");
	test_input_just_one_pipe();
	printf("\nTOKEN LISTE TEST PIPE AND INPUT REDIR:\n\n");
	test_input_pipe_and_input_redir();
	printf("\nTOKEN LISTE TEST PIPE AND REDIRECTIONS:\n\n");
	test_input_pipe_and_redirs();
	printf("TOKEN LIST TEST HEREDOC\n\n");
	test_input_heredoc();
	printf("TOKEN LIST TEST ONE WORD:\n\n");
	test_input_just_one_word();
	printf("TOKEN LIST TEST TWO WORDS:\n\n");
	test_input_two_words();
	printf("TOKEN LIST TEST ONE WORD WITH DOUBLE QUOTES:\n\n");
	test_input_word_with_double_quotes();
	printf("TOKEN LIST TEST ONE WORD WITH SIMPLE QUOTES:\n\n");
	test_input_word_with_simple_quotes();
}
//COUCOU LS
