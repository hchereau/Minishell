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

void	received_signal(void)
{
	struct sigaction	s_int;
	struct sigaction	s_quit;


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
