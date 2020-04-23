/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:35:44 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 17:18:01 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			width(const char *str, va_list ap)
{
	int		size;
	int		odd;

	size = 0;
	if (*str == '0')
		str++;
	odd = (*str == '-') ? -1 : 1;
	while (*str == '-' || *str == '0')
		str++;
	if (ft_isdigit(*str))
		size = odd * ft_atoi(str);
	else if (*str == '*')
		if ((size = va_arg(ap, int)) >= 0)
			size = odd * size;
	return (size);
}

int			precision(const char *str, const char *dst, va_list ap)
{
	int		size;

	size = -1;
	while (str < dst)
	{
		if (*str++ == '.')
		{
			size = 0;
			if (ft_isdigit(*str))
				size = ft_atoi(str);
			else if (*str == '*')
				if ((size = va_arg(ap, int)) < 0)
					size = -1;
		}
	}
	return (size);
}

int			put_count(char *str, char c, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		if (!str)
			while (i++ < len)
				write(1, &c, 1);
		else
			write(1, str, len);
	}
	else
		len = 0;
	return (len);
}

char		*position(const char *str)
{
	while (*str && !(ft_strchr("cspdiuxX%", *str)))
		str++;
	return ((char *)str);
}

char		*get_arg(char c, va_list ap)
{
	char	*s;

	if (c == 'p')
		return (ft_ltoa_base(va_arg(ap, long), "0123456789abcdef"));
	if (c == 's')
		return (!(s = va_arg(ap, char *))) ? ft_strdup("(null)") : ft_strdup(s);
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'u')
		return (ft_utoa(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_ltoa_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_ltoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (0);
}
