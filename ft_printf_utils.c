#include "ft_printf.h"

ssize_t	ft_putchar(char *c)
{
	return (write(1, c, 1));
}

ssize_t	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

ssize_t	ft_put_format(const char *format, va_list ptr)
{
	char	buf;

	format++;
	if (*format == 'c')
	{
		buf = va_arg(ptr, int);
		return (ft_putchar(&buf));
	}
	else if (*format == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (*format == 'p')
		return (ft_putaddr((uintptr_t)va_arg(ptr, void *), 0));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_signed(va_arg(ptr, signed int), 0, 1));
	else if (*format == 'u')
		return (ft_putnbr_unsigned(va_arg(ptr, unsigned int), 0, 1));
	else if (*format == 'x' || *format == 'X')
		return (ft_putnb_hex(va_arg(ptr, unsigned int), *format, 0, 1));
	else if (*format == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &format, 1));
}
