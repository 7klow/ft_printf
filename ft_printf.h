/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:52 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/29 10:39:23 by ncontrem         ###   ########.fr       */
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
char			*int_hexa(unsigned int nb, int is_upper);
char			*ft_utoa(unsigned int n);

#endif