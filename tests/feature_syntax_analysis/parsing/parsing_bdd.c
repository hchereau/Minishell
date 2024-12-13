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

void	parsing_bdd_valid_syntax(void)
{
	test_simple_command_no_options_valid();
	//test_simple_command_valid(WORD, WORD);
}
void	parsing_bdd_tests(void)
{
	parsing_bdd_valid_syntax();
}
