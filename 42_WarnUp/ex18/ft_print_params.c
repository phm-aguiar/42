/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:56:28 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/11 18:13:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	counter;
	int	counter2;

	counter = 1;
	while (counter < argc)
	{
		counter2 = 0;
		while (argv[counter][counter2] != '\0')
		{
			ft_putchar(argv[counter][counter2]);
			counter2++;
		}
		ft_putchar('\n');
		counter++;
	}
}
