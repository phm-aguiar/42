/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:43:11 by phenriq2          #+#    #+#             */
/*   Updated: 2023/07/13 14:07:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	counter;

	counter = 0;
	while ((s1[counter] != '\0' && s2[counter] != '\0')
		&& (s1[counter] == s2[counter]))
	{
		counter++;
	}
	return ((unsigned char)s2[counter] - (unsigned char)s1[counter]);
}

void	change(char **a1, char **a2)
{
	char	*temp;

	temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

void	draw(char **a1, int a2)
{
	int	counter;
	int	counter2;

	counter = 1;
	while (counter < a2)
	{
		counter2 = 0;
		while (a1[counter][counter2] != '\0')
		{
			ft_putchar(a1[counter][counter2]);
			counter2++;
		}
		ft_putchar('\n');
		counter++;
	}
}

int	main(int argc, char **argv)
{
	int	counter;
	int	counter2;

	counter = 1;
	while (counter < argc)
	{
		counter2 = argc - 1;
		while (counter2 > counter)
		{
			if (ft_strcmp(argv[counter], argv[counter2]) < 0)
			{
				change(&argv[counter], &argv[counter2]);
			}
			counter2--;
		}
		counter++;
	}
	draw(argv, argc);
}
