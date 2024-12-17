/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:44 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:15:01 by tchobert         ###   ########.fr       */
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

void	test_create_token(void);
void	test_delete_token(void);
void	test_add_token_to_token_list(void);
void	test_delete_token_list(void);
void	test_extract_lexem_from_user_input(void);

// PARSING

void	print_token_list(t_token_list token_list);

void	parsing_bdd_tests(void);
void	parsing_bdd_valid_syntax(void);
void	test_simple_command_no_options_valid(void);

#endif
