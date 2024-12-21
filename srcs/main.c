/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:39 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/14 16:25:29 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#ifndef TEST_MODE

static int	main_process(char *user_input_line)
{
	if (user_input_line == CTRL_D)
	{
		exit_shell_routine();
	}
	return (EXIT_SUCCESS);
}

static int	core_routine(void)
{
	char	*user_input_line;

	user_input_line = NULL;
	while (MSH_LOOP)
	{
		user_input_line = prompt_gets_user_input();
		main_process(user_input_line);
		free(user_input_line);
	}
	return (EXIT_SUCCESS);
}

static int	launch_shell(void)
{
	struct sigaction	sa;

	setup_signals(&sa);
	return (core_routine());
}

int	main(void)
{
	return (launch_shell());
}
#endif
