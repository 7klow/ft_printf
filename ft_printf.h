/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:52 by ncontrem          #+#    #+#             */
/*   Updated: 2025/11/01 12:27:44 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
char			*addr_hexa(void *addr);
char			*hexa_lower(unsigned int nb);
char			*hexa_upper(unsigned int nb);
char			*ft_utoa(unsigned int n);
int				ft_putstr_count_free(char *s);

#endif