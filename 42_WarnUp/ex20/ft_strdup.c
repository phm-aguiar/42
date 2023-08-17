/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:43:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/13 18:34:22 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		counter;
	char	*copy;

	counter = 0;
	while (src[counter] != '\0')
	{
		counter++;
	}
	copy = malloc(counter + 1);
	counter = 0;
	while (src[counter] != '\0')
	{
		copy[counter] = src[counter];
		counter++;
	}
	copy[counter] = '\0';
	return (copy);
}
