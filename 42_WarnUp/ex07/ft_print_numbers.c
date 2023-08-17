/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:08:09 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/12 11:44:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char number);

void	ft_print_numbers(void)
{
	int	counter;

	counter = '0';
	while (counter <= '9')
	{
		ft_putchar(counter);
		counter++;
	}
}
