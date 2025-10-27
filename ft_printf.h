/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:52 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/27 20:11:44 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char			*ft_free_strjoin(char *s1, char *s2);
char			*add_char(char *str, char c);
unsigned long	ft_nbrlen(long nb);
char			*ft_utoa(unsigned int n);
char			*get_addr_hexa(void *addr);
void			str_toupper(char *str);
char			*get_int_hexa(int nb, int is_toupper);

#endif