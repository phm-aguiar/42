/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marvim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:57:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/06/23 13:16:02 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fazer isso .... "\?$*'MaRViN'*$?\"
#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_message(char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		if (message[i] == '$' || message[i] == '*')
		{
			print_char('%');
			print_char(message[i]);
		}
		else
		{
			print_char(message[i]);
		}
		i++;
	}
}

int	main(void)
{
	print_message("\"?$*'MaRViN'*$?\"");
	return (0);
}
