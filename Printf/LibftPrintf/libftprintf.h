/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:50:17 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/21 16:43:14 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define CONVERTER "cspdiuxX%"
# define HEXADECIMAL "0123456789abcdef"
# define NEGHEXA "fedcba9876543210"
# define HEXADECIMALUP "0123456789ABCDEF"
# define NEGHEXAUP "FEDCBA9876543210"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_printf
{
	int			padding;
	int			width;
	int			precision;
	int			count;
	char		type;
}				t_printf;

int				ft_checkc(char c, const char *info);
int				ft_printf(const char *format, ...);
int				ft_size_s(t_printf *info, char *arg);
int				ft_calci(unsigned int nbr);
int				ft_calchexa(int nb);
int				ft_calcp(long nb);

long			ft_abs(long nb);

const char		*ft_checkflag(const char *format, t_printf *info);
const char		*ft_checkwidth(const char *format, t_printf *info, va_list va);
const char		*ft_checkprecision(const char *format, \
					t_printf *info, va_list va);
const char		*ft_checktype(const char *format, t_printf *info);
const char		*ft_fillstruct(const char *format, t_printf *info, va_list va);

void			ft_putchar(char c, t_printf *info);
void			ft_putnbr(int nb, t_printf *info);
void			ft_init_struct(t_printf *info);
void			ft_init_struct_wc(t_printf *info);
void			ft_prints(t_printf *info, va_list *va);
void			ft_printfs(t_printf *info, char *arg);
void			ft_space_s_front(t_printf *info, int size);
void			ft_space_s_back(t_printf *info, int size);
void			ft_printdi(t_printf *info, va_list *va);
void			ft_putstr(char *str, t_printf *info);
void			ft_whattoprint(t_printf *info, va_list *va);
void			ft_space_di_front(t_printf *info, int size, int arg);
void			ft_space_di_back(t_printf *info, int size, int arg);
void			ft_checksize_di(int size, t_printf *info, int arg);
void			ft_do_printdi(t_printf *info, int size, int arg);
void			ft_printc(t_printf *info, va_list *va);
void			ft_space_u_front(t_printf *info, int size);
void			ft_checksize_u(int size, t_printf *info);
void			ft_space_u_back(t_printf *info, int size);
void			ft_printu(t_printf *info, va_list *va);
void			ft_do_printu(t_printf *info, int size, int arg);
void			ft_putnbru(unsigned int nb, t_printf *info);
void			ft_putnbrhexa(int nb, t_printf *info);
void			ft_putnbrhexaneg(long nb, t_printf *info);
void			ft_putsomef(int size, t_printf *info);
void			ft_printx(t_printf *info, va_list *va);
void			ft_space_x_front_neg(t_printf *info);
void			ft_checksize_x(int size, t_printf *info);
void			ft_checksize_x_neg(t_printf *info);
void			ft_space_x_front(t_printf *info, int size);
void			ft_space_x_back(t_printf *info, int size);
void			ft_space_x_back_neg(t_printf *info);
void			ft_printxup(t_printf *info, va_list *va);
void			ft_putsomefup(int size, t_printf *info);
void			ft_putnbrhexanegup(long nb, t_printf *info);
void			ft_putnbrhexaup(int nb, t_printf *info);
void			ft_do_printx(t_printf *info, int size, int arg);
void			ft_do_printxup(t_printf *info, int size, int arg);
void			ft_printp(t_printf *info, va_list *va);
void			ft_putnbrp(long nb, t_printf *info);
void			ft_putnbrpneg(long nb, t_printf *info);
void			ft_space_p_front_neg(t_printf *info);
void			ft_space_p_back_neg(t_printf *info);
void			ft_space_p_front(t_printf *info, int size);
void			ft_space_p_back(t_printf *info, int size);
void			ft_putsomefp(int size, t_printf *info);
void			ft_do_printp(t_printf *info, int size, long arg);
void			ft_printperc(t_printf *info, va_list *va);
void			ft_space_perc_back(t_printf *info);
void			ft_checksize_perc(t_printf *info);
void			ft_space_perc_front(t_printf *info);

size_t			ft_strlen(const char *str);

#endif
