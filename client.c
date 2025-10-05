/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibsenad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:12:02 by hibsenad          #+#    #+#             */
/*   Updated: 2025/10/05 21:32:00 by hibsenad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	int	signal_to_send;

	// Détermine le signal à envoyer en fonction de la valeur du bit.
	if (bit == 1)
	{
		signal_to_send = SIGUSR1; // Si le bit est 1, on envoie SIGUSR1.
	}
	else
	// Sinon (si le bit est 0,ou n'importe quelle autre valeur considérée comme fausse).
	{
		signal_to_send = SIGUSR2; // On envoie SIGUSR2.
	}
	// Tente d'envoyer le signal déterminé au PID du serveur.
	if (kill(pid, signal_to_send) == -1)
	{
		ft_printf("Error: Unable to send signal to PID %d\n", pid);
		exit(EXIT_FAILURE);
	}
	usleep(500); // Maintient le délai pour la fiabilité.
}

void	send_character(pid_t pid, unsigned char character)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (character >> i) & 1;
		send_bit(pid, bit);
		i++;
	}
}

void	transmit_message(pid_t pid, char *message)
{
	while (*message)
	{
		send_character(pid, *message);
		message++;
	}
	// Envoyer un caractère nul pour signaler la fin du message
	send_character(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID.\n");
		return (EXIT_FAILURE);
	}
	message = argv[2];
	transmit_message(pid, message);
	return (EXIT_SUCCESS);
}
