/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:59:34 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/11 11:06:40 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt_get_user_input(void)
{
	char	*user_input_line;

	user_input_line = readline(MSH_PROMPT);
	return (user_input_line);
}
