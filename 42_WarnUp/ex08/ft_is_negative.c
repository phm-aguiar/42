/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:14:31 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/10 18:29:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char letter);

void	ft_is_negative(int n)
{
	int	neg_pos;

	neg_pos = n >= 0;
	if (neg_pos)
		ft_putchar('P');
	else
		ft_putchar('N');
}
