/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:01:04 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/18 17:01:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

// INCLUDES

#include "minishell.h"

// DEFINES

# define LEXER_DICTIONARY "|"

// TYPEDEFS

//typedefs

typedef t_list *	t_token_list;
typedef char *		t_lexem;

// ENUMS

typedef enum e_token_type
{
	TOKEN_LIST_START,
	TOKEN_LIST_END,
	WORD,
	PIPE,
	INPUT_REDIR_OPERATOR,
	OUTPUT_REDIR_OPERATOR,
	APPEND_OPERATOR,
	HEREDOC_OPERATOR,
	UNKNOWN_OPERATOR
}			t_token_type;

typedef enum e_syntax_status
{
	VALID_SYNTAX,
	INVALID_SYNTAX
}			t_syntax_status;

// STRUCTURES

typedef struct s_token
{
	t_lexem			token_lexem;
	t_token_type	token_type;
}				t_token;

// PROTOTYPES

t_token_list	minishell_lexes_user_command_line(const char *user_command_line);
t_token			*create_token(char *lexem, t_token_type token_type);
t_token_list	add_token_to_token_list(t_token_list token_list,
					t_lexem token_lexem, t_token_type token_type);
void			print_token(void *content);
void			print_token_list(t_token_list token_list);

#endif
