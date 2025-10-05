/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibsenad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:51:31 by hibsenad          #+#    #+#             */
/*   Updated: 2025/10/05 16:21:58 by hibsenad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <stdio.h>

void	send_bit(pid_t pid, int bit);
void	send_character(pid_t pid, unsigned char character);
void	transmit_message(pid_t pid, char *message);
void	handle_character(unsigned char *character, int *bit_count);
void	signal_handler(int sig, siginfo_t *info, void *context);

#endif