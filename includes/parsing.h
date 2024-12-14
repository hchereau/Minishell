/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:57:07 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 17:15:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// INCLUDES

// DEFINES

// TYPEDEFS

typedef size_t	t_token_number;

// ENUMS

typedef enum e_token_type
{
	ENTRY_START,
	ENTRY_END,
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
	NO_SYNTAX,
	VALID_SYNTAX,
	INVALID_SYNTAX
}			t_syntax_status;

// STRUCTURES

typedef struct s_token			t_token;
typedef struct s_token_list		t_token_list;

typedef struct s_token
{
	t_token_type	token_type;
	t_token			*next_token;
}				t_token;

typedef struct s_token_list
{
	t_token			*entry_start;
	//t_token_number	tokens_number;
}				t_token_list;

// PROTOTYPES

t_syntax_status	syntax_analyser(t_token_list tokenized_input);

#endif
