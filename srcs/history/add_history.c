/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:35:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/11 13:56:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_user_input_line_to_history(const char *user_input_line)
{
	if (user_input_line != NULL)
	{
		add_history(user_input_line);
	}
}
