/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:33:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/21 15:33:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_space(const char current_char)
{
	return (current_char == ' ');
}

bool	is_separator(const char current_char)
{
	size_t	i;

	i = 0;
	if (is_space(current_char) == true)
		return (true);
	while (LEXER_DICTIONARY[i] != '\0')
	{
		if (LEXER_DICTIONARY[i] == current_char)
			return (true);
		++i;
	}
	return (false);
}
