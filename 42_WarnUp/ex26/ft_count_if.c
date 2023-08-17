/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:13:11 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/16 16:10:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (tab[i] && tab[i][0])
	{
		if (f(tab[i]))
			counter++;
		i++;
	}
	return (counter);
}
