/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:58:15 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/11 16:54:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	flag_c_bonus(va_list args);
int	flag_percent_bonus(void);
int	flag_s_bonus(va_list args);
int	flag_di_bonus(va_list args, int flag);
int	flag_u_bonus(va_list args, int flag);
int	flag_x_bonus(va_list args, int flag);
int	flag_x2_bonus(va_list args, int flag);
int	flag_p_bonus(va_list args);
int	flag_space_bonus(void);
#endif