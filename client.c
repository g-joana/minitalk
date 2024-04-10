#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	sendkill(int pid, char *s)
{
	int	i = 0;
	int	b;

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
