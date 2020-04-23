/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:35:44 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 17:21:30 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print(char *s, char c, int w, int p)
{
	int		len;
	int		count;
	char	tmp;

	count = 0;
	tmp = *s;
	len = (*s == '0' && p == 0) ? 0 : (int)ft_strlen(s);
	if (p >= len)
		len = (*s == '-') ? p + 1 : p;
	if (*s == '-' && c == '0')
		count += put_count(s++, 0, 1);
	count += put_count(NULL, c, w - len);
	if (*s == '-')
		count += put_count(s++, 0, 1);
	count += put_count(NULL, '0', len - (int)ft_strlen(s));
	if (p != 0 || tmp != '0')
		count += put_count(s, 0, ft_strlen(s));
	free(s);
	return (count);
}

int	p_print(char *s, char c, int w, int p)
{
	int	len;
	int	count;

	count = 0;
	len = (p == 0) ? 0 : (int)ft_strlen(s);
	count += put_count(NULL, c, w - len - 2);
	count += put_count("0x", 0, 2);
	count += put_count(NULL, '0', p - len);
	count += put_count(s, 0, len);
	count += put_count(NULL, ' ', -w - count);
	free(s);
	return (count);
}

int	s_print(char *s, char c, int w, int p)
{
	int	len;
	int	count;

	count = 0;
	len = (p != -1 && p < (int)ft_strlen(s)) ? p : (int)ft_strlen(s);
	count += put_count(NULL, c, w - len);
	count += put_count(s, 0, len);
	count += put_count(NULL, ' ', -w - count);
	free(s);
	return (count);
}

int	conv(const char *str, char id, va_list ap)
{
	char	c;
	int		w;
	int		p;
	int		count;

	count = 0;
	w = width(str + 1, ap);
	p = precision(str, position(str + 1), ap);
	c = (*(str + 1) == '0' && p == -1) ? '0' : ' ';
	if (id == 'p')
		count = p_print(get_arg(id, ap), c, w, p);
	else if (id == 's')
		count = s_print(get_arg(id, ap), c, w, p);
	else if (id != 'c' && id != '%' && id != 'p' && id != 's')
		count = print(get_arg(id, ap), c, w, p);
	else if (id == 'c' || id == '%')
	{
		id = (id == 'c') ? (char)va_arg(ap, int) : '%';
		count += put_count(NULL, c, w - 1);
		count += put_count(NULL, id, 1);
	}
	count += put_count(NULL, ' ', -w - count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += conv(str, *(position(str + 1)), ap);
			str = position(str + 1) + 1;
		}
		else
			count += put_count((char *)str++, 0, 1);
	}
	va_end(ap);
	return (count);
}
