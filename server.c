#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	handle_bit(int signal)
{
	static char	byte = '\0';
	static int	count = 7;

	if(signal == SIGUSR1)
	{
		byte = byte | (1 << count--);
	}
	else if (signal == SIGUSR2)
	{
		count--;
	}
	if (count == -1)
	{
		ft_printf("%c", byte);
		count = 7;
		byte = '\0';
	}
}

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, handle_bit);
	signal(SIGUSR2, handle_bit);
	while (1);
	return (0);
}
