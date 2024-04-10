/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:46:29 by jgils             #+#    #+#             */
/*   Updated: 2024/04/10 15:53:45 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	sendkill(int pid, char *s)
{
	int	i;
	int	b;

	i = 0;
	while (*s && s[i] != '\0')
	{
		b = 7;
		while (b >= 0)
		{
			if (s[i] & (1 << b))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b--;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 3)
		return (1);
	sendkill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
