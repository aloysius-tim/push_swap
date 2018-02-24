/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:50:31 by tkeynes           #+#    #+#             */
/*   Updated: 2018/02/07 14:50:32 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdio.h>

# define OPTION_SHARP 0
# define OPTION_ZERO 1
# define OPTION_LESS 2
# define OPTION_PLUS 3
# define OPTION_SPACE 4

# define SIZE_CHAR 6
# define SIZE_SHORT 7
# define SIZE_INT 8
# define SIZE_INT_MAX 9
# define SIZE_LONG 10
# define SIZE_SIZE_T 11
# define SIZE_LONG_LONG 12

# define CONV_STRING 1
# define CONV_STRING_CAPS 2
# define CONV_CHAR 3
# define CONV_CHAR_CAPS 4
# define CONV_OCTAL 5
# define CONV_OCTAL_CAPS 6
# define CONV_HEXA 7
# define CONV_HEXA_CAPS 8
# define CONV_INT 9
# define CONV_LONG_INT 10
# define CONV_UNSIGNED_INT 11
# define CONV_UNSIGNED_LONG_INT 12
# define CONV_ADRESS 13
# define CONV_NONE 14

typedef struct		s_flags
{
	int				*options;
	int				width;
	int				precision;
	int				size_modifier;
	char			conv;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_read(va_list arg, char *str);

t_flags				ft_parse(char **str);
void				ft_flag_init(t_flags *flags);
int					ft_is_end(char c);
int					ft_get_size_modifier_2(char **str);
int					ft_get_size_modifier(char **str);
int					ft_get_conv(char **str, int force);
void				ft_flag_optm(t_flags *flags);
void				ft_flag_optm2(t_flags *flags);

int					ft_get_options(char **str);
int					ft_get_width(char **str);
int					ft_get_precision(char **str);
int					ft_get_size_modifier(char **str);
int					ft_get_size_modifier_2(char **str);
int					ft_get_conv(char **str, int force);

int					ft_get_size_number_long_long(long long int n);
int					ft_get_size_number(int n);
int					ft_get_size_number_long_long_unsigned(
unsigned long long int n);
int					ft_get_size_number_base(unsigned long long int n, int base);
int					ft_size_binary(wchar_t i);

int					ft_putnbr_long_long(long long int nb);
int					ft_putnbr_unsigned_long_long(unsigned long long int nb);
int					ft_putnbr_unsigned(unsigned int nb);
void				ft_putstr_reverse(char *str, int size);
int					ft_putnbr_base(unsigned long long int i, int base,
int caps);

int					ft_print(va_list arg, t_flags flag);
int					ft_print_2(va_list arg, t_flags flag);
int					ft_print_c_char(int arg, t_flags flag);
int					ft_get_size(t_flags flag, int *arg);
int					ft_print_string(int *arg, t_flags flag);
int					ft_print_space(int n);
int					ft_print_zero(int n);
int					ft_print_hexa(t_flags conv, int count,
unsigned long long int arg);
int					ft_print_hexa_long_long(unsigned long long int arg,
t_flags conv);
int					ft_print_int(int arg, t_flags conv);
int					ft_print_number(long long int arg, t_flags conv, int size,
int before);
int					ft_print_long_long_int(long long int arg, t_flags conv);
int					ft_print_octal(t_flags conv, int count, int before,
unsigned long long int arg);
int					ft_print_octal_long_long(unsigned long long int arg,
t_flags conv);
int					ft_print_int_max(intmax_t arg, t_flags conv);
int					ft_print_sizet(size_t arg, t_flags conv);
int					ft_print_none(t_flags conv);
int					ft_print_int_unsigned(unsigned int arg, t_flags conv);
int					ft_print_unsigned(t_flags conv, int count, int size,
unsigned long long int arg);
int					ft_print_long_long_int_unsigned(unsigned long long int arg,
t_flags conv);
int					ft_putstr_w(wchar_t *str, int size);
int					ft_len_w(wchar_t va);
int					ft_strlen_w(wchar_t *str);
int					ft_strclen_w(wchar_t *str, int size);
#endif
