/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:46:42 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/12 14:32:38 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_interface.h"

void	init_signals(struct sigaction *sa)
{
	memset(sa, 0, sizeof(struct sigaction));
	sa->sa_handler = signal_handler;
	if (sigaction(SIGINT, sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	sigint_routine(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		sigint_routine();
	}
}
