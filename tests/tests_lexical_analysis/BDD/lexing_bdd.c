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
	test_input_just_one_letter();
	printf("\nTOKEN LISTE TEST PIPE AND INPUT REDIR:\n\n");
	test_input_pipe_and_input_redir();
	printf("\nTOKEN LISTE TEST PIPE AND REDIRECTIONS:\n\n");
	test_input_pipe_and_redirs();
	// printf("\nTOKEN LISTE TEST OPERATORS AND ONE CHAR 'a':\n\n");
	// test_input_operators_and_one_char();
}
//COUCOU LS
