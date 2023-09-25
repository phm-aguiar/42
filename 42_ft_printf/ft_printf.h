/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:58:15 by phenriq2          #+#    #+#             */
/*   Updated: 2023/09/13 11:02:10 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	tratament_flags_advanced(char chr, int *index);
int	tratament_flags(char chr, va_list args, int flag);
int	flag_c(va_list args);
int	flag_percent(void);
int	flag_s(va_list args);
int	flag_di(va_list args, int flag);
int	flag_u(va_list args, int flag);
int	flag_x(va_list args, int flag);
int	flag_x2(va_list args, int flag);
int	flag_p(va_list args);
int	flag_space(void);
#endif