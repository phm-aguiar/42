/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:58:15 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/09 07:53:08 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int	ft_printf(const char *string, ...);
int	flag_c(va_list args);
int	flag_percent(void);
int	flag_s(va_list args);
int	flag_di(va_list args);
int	flag_u(va_list args);
int	flag_x(va_list args);
int	flag_x2(va_list args);
int	flag_p(va_list args);
int	flag_space(void);

#endif