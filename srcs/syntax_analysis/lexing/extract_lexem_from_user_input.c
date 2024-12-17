/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_lexem_from_user_input.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:09:27 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/17 19:09:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_lexem_size(char *lexem_start, char *lexem_end)
{
	const size_t	lexem_size = (lexem_end - lexem_start);
	return (lexem_size);
}

t_lexem	extract_lexem_from_user_input(char *lexem_start, char *lexem_end)
{
	t_lexem	lexem;
	size_t	lexem_size;

	if (*lexem_start == '\0')
		return (ft_strdup(""));
	lexem_size = get_lexem_size(lexem_start, lexem_end);
	lexem = ft_strndup(lexem_start, lexem_size);
	return (lexem);
}
