/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:39 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/10 18:05:41 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	main_process(char *user_input_line)
{
	user_input_line = readline(MSH_PROMPT);
	if (user_input_line == CTRL_D)
	{
		exit_shell_routine();
	}
	free(user_input_line);
	return (EXIT_SUCCESS);
}

static int	core_routine(void)
{
	char	*user_input_line;

	user_input_line = NULL;
	while (MSH_LOOP)
	{
		main_process(user_input_line);
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
