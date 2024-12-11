/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:59:34 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/11 13:49:57 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prompt_asks_next_history_entry(const char *user_input_line)
{
	add_user_input_line_to_history(user_input_line);
}

char	*prompt_gets_user_input(void)
{
	char	*user_input_line;

	user_input_line = readline(MSH_PROMPT);
	prompt_asks_next_history_entry(user_input_line);
	return (user_input_line);
}
