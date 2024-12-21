/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_lexer_dictionary.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:29:41 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/21 15:29:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	search_operator_in_lexer_dictionary(const char operator)
{
	t_token_type	type;
	size_t			i;

	i = 0;
	while (LEXER_DICTIONARY[i] != '\0')
	{
		if (LEXER_DICTIONARY[i] == operator)
		{
			type = (t_token_type)i;
			return (type);
		}
		++i;
	}
	return (FAILURE);
}
