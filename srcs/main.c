/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:39 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/10 14:32:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	core_routine(void)
{
	char	*user_input_line;

	user_input_line = NULL;
	while (MSH_LOOP)
	{
		user_input_line = readline(MSH_PROMPT);
		free(user_input_line);
	}
	return (EXIT_SUCCESS);
}

static int	launch_shell(void)
{
	return (core_routine());
}

int	main(void)
{
	return (launch_shell());
}
