/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:57:07 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 18:41:10 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// INCLUDES

// DEFINES

// TYPEDEFS

typedef size_t	t_token_number;

// ENUMS

typedef enum e_machine_state
{
	STRING_START,
	IN_WORD,
	IN_QUOTES,
	STRING_END
}			t_machine_state;


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
	NO_SYNTAX,
	VALID_SYNTAX,
	INVALID_SYNTAX
}			t_syntax_status;

typedef enum e_token_add_status
{
	ADD_SUCCESS,
	ADD_FAILURE
}			t_token_add_status;

// STRUCTURES

typedef struct s_token			t_token;
typedef struct s_token_list		t_token_list;

typedef struct s_token
{
	t_token_type	token_type;
	char			*token_content;
	t_token			*previous_token;
	t_token			*next_token;
}				t_token;

typedef struct s_token_list
{
	t_token			*token_list_first_token;
	t_token			*token_list_last_token;
	//t_token_number	tokens_number;
}				t_token_list;

typedef struct e_lexing_machine
{
	char			*input_str;
	t_token_list	input_token_list;
	t_machine_state	current_state;
}			t_lexing_machine;

// PROTOTYPES

// LEXING

t_token_list		build_token_list_from_user_input(char *user_input);
t_token				*create_token(char *new_token_content,
						t_token_type new_token_type);
t_token_add_status	add_token_to_token_list(t_token_list *token_list,
						t_token *token_to_add);
void				delete_token(t_token *token_to_delete);

// PARSING

t_syntax_status	syntax_analyser(t_token_list tokenized_input);

#endif
