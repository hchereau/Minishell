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

// TYPEDEFS

//typedefs

typedef t_list		t_token;
typedef t_list *	t_tokens_list;
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

typedef struct s_token_content
{
	t_lexem			token_lexem;
	t_token_type	token_type;
}				t_token_content;

// PROTOTYPES

t_tokens_list	minishell_lexes_user_command_line(char *user_command_line);

#endif
