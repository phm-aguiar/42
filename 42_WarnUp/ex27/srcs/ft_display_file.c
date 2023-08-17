/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:16:13 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/17 17:35:49 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

int	main(int argc, char **argv)
{
	int		file;
	char	c;

	file = -1;
	if (argc != 2)
	{
		arg_test(argc);
	}
	else
	{
		file = open(argv[argc - 1], O_RDONLY);
		if (file > 0)
		{
			while (read(file, &c, 1) > 0)
			{
				ft_putchar(c);
			}
		}
	}
	close(file);
}
