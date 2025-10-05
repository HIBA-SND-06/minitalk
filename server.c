/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibsenad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:04:29 by hibsenad          #+#    #+#             */
/*   Updated: 2025/10/05 20:10:15 by hibsenad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*

	* Traite le caractère complet (après 8 bits reçus) et réinitialise les compteurs.
 */
void	handle_character(unsigned char *character, int *bit_count)
{
	if (*bit_count == 8)
	{
		if (*character == '\0')
		{
			// Caractère nul reçu : fin de chaîne, affiche un saut de ligne.
			ft_putstr("\n(Message reçu)\n");
		}
		else
		{
			// Caractère standard : affiche-le.
			write(1, character, 1);
		}
		// Réinitialisation pour le caractère suivant.
		*character = 0;
		*bit_count = 0;
	}
}

/*
 * Gestionnaire de signaux : reçoit les bits et reconstruit le caractère.
 */
void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;

	(void)info; // Non utilisé car le serveur n'envoie pas d'ACK.
	(void)context;
	// 1. Accumulation du bit (LSB first)
	// SIGUSR1 = bit à 1. SIGUSR2 = bit à 0.
	if (sig == SIGUSR1)
		character |= (1 << bit_count);
	bit_count++;
	// 2. Traitement si le caractère est complet
	handle_character(&character, &bit_count);
	// IMPORTANT : Aucune fonction kill() ici car le client ne gère pas d'ACK.
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	// Configuration du gestionnaire de signaux
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
		// Nécessaire même si info n'est pas utilisé,pour la convention 42.
	sigemptyset(&sa.sa_mask);
	// Associe la structure 'sa' aux deux signaux
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		ft_putstr("Error: Unable to set up signal handlers.\n");
		return (EXIT_FAILURE);
	}
	// Affichage du PID pour le client
	server_pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putstr("\nWaiting for messages...\n");
	// Boucle d'attente
	while (1)
		pause();
	return (0);
}
