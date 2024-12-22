/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:52:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/22 16:21:15 by linux            ###   ########.fr       */
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

	// LEXING

	RUN_TEST(lexing_bdd_tests);
    RUN_TEST(test_env_builtin_should_display_environment_variables);

	return (UNITY_END());
}
