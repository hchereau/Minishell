/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bdd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:25:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/13 19:48:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	parsing_bbd_valid_syntax(void)
{
	test_simple_command_valid(ENTRY_START, WORD, ENTRY_END);
	//test_simple_command_valid(WORD, WORD);
}
void	parsing_bbd_tests(void)
{
	parsing_bdd_valid_syntax();
}
