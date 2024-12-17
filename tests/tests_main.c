/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:52:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:14:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void setUp(void)
{

}
void tearDown(void)
{

}

int	main(void)
{
	UNITY_BEGIN();

	printf("\n");
	//LEXING
	RUN_TEST(lexing_bdd_tests);
	printf("\n");
	RUN_TEST(test_create_token);
	printf("\n");
	RUN_TEST(test_delete_token);
	printf("\n");
	RUN_TEST(test_add_token_to_token_list);
	printf("\n");
	RUN_TEST(test_delete_token_list);
	printf("\n");
	RUN_TEST(test_extract_lexem_from_user_input);
	printf("\n");

	// PARSING
	RUN_TEST(parsing_bdd_tests);
	return (UNITY_END());
}
