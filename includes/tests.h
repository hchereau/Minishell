/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:44 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/22 16:12:13 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

// INCLUDES

# include "unity.h"
# include "libft.h"
# include "minishell.h"

/// PROTOTYPES ///

// LEXING

void	lexing_bdd_tests(void);
void	test_input_empty_string(void);
void test_env_builtin_should_display_environment_variables();

// PARSING

#endif
