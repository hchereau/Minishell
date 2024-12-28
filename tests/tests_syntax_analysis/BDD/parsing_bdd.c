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

static void	parsing_bdd_invalid_syntax(void)
{
	test_input_just_a_pipe();
}
void	parsing_bdd_tests(void)
{
	parsing_bdd_invalid_syntax();
}
