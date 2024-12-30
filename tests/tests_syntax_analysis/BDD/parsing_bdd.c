/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bdd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:25:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/13 21:29:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void parsing_bdd_valid_syntax(void)
{
	test_input_empty_string();
}

static void	parsing_bdd_invalid_syntax(void)
{
	test_input_just_a_pipe();
	test_input_two_pipes();
}
void	parsing_bdd_tests(void)
{
	parsing_bdd_invalid_syntax();
	parsing_bdd_valid_syntax();
	test_free();
}
