#include <stdarg.h>
#include <unistd.h>
#define BASE "0123456789"
#define BASEX "0123456789abcdef"
#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int print_size;

int numlen(long long num, int base)
{
	int i;

	i = 1;
	while ((num /= base) > 0)
		++i;
	return (i);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void ft_putnbr(long long num, int base, char *bs )
{
	if(num > 9)
		ft_putnbr(num / base, base, bs);
	print_size += write(1, &bs[num % base], 1);
}

int ft_printf(char *format, ...)
{
	va_list ap;
	int i;
	int width;
	int dot;
	int pre;
	int idx;

	print_size = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		idx = 0;
		width = 0;
		dot = 0;
		pre = 0;
		if (format[i] == '%')
		{
			++i;
			while (format[i] != 's' && format[i] != 'd' && format[i] != 'x' && format[i] != '\0')
			{
				if (format[i] == '.')
				{
					dot = 1;
					++i;
				}
				else if (dot == 0)
				{
					while (format[i] >= '0' && format[i] <= '9')
					{
						width = width * 10 + (format[i] - '0');
						++i;
					}
				}
				else
					while (format[i] >= '0' && format[i] <= '9')
					{
						pre = pre * 10 + (format[i] - '0');
						++i;
					}
			}
			if (format[i] == 's')
			{
				char *s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				if (dot == 1 && pre == 0)
					s = "";
				if (dot == 0)
					pre = ft_strlen(s);
				while (idx < width - min(ft_strlen(s), pre))
				{
					print_size += write(1, " ", 1);
					++idx;
				}
				idx = 0;
				while (idx < min(ft_strlen(s), pre))
				{
					print_size += write(1, &s[idx], 1);
					++idx;
				}
			}
			else if(format[i] == 'd')
			{
				long long num = va_arg(ap, int);
				if (num < 0)
				{
					print_size += write(1, "-", 1);
					num *= -1;
				}
				if (num == 0 && dot == 1 && pre == 0)
					++width;
				while (idx < width - max(pre, numlen(num, 10)))
				{
					print_size += write(1, " ", 1);
					++idx;
				}
				idx = 0;
				while (idx < pre - numlen(num, 10))
				{
					print_size += write(1, "0", 1);
					++idx;
				}
				if (num == 0 && dot == 1 && pre == 0)
					;
				else
					ft_putnbr(num, 10, BASE);
			}
			else if(format[i] == 'x')
			{
				long long num = va_arg(ap, unsigned int);
				if (num == 0 && dot == 1 && pre == 0)
					++width;
				while (idx < width - max(pre, numlen(num, 16)))
				{
					print_size += write(1, " ", 1);
					++idx;
				}
				idx = 0;
				while (idx < pre - numlen(num, 16))
				{
					print_size += write(1, "0", 1);
					++idx;
				}
				if (num == 0 && dot == 1 && pre == 0)
					;
				else
					ft_putnbr(num, 16, BASEX);
			}
			else
				--i;
		}
		else
			print_size += write(1, &format[i], 1);
		++i;
	}
	return (print_size);
}

// #include <stdio.h>
// int main()
// {
// 	int test;
// 	int real;
// 	real = printf("%s\n", NULL);
// 	test = ft_printf("%s\n", NULL);
// 	printf("test : %d, real : %d\n", test, real);

// 	real = printf("%.d\n", 10);
// 	test = ft_printf("%.d\n", 10);
// 	printf("test : %d, real : %d\n", test, real);

// 	real = printf("%.d\n", 0);
// 	test = ft_printf("%.d\n", 0);
// 	printf("test : %d, real : %d\n", test, real);

// 	real = printf("%20x\n", 0);
// 	test = ft_printf("%20x\n", 0);
// 	printf("test : %d, real : %d\n", test, real);

// 	real = printf("%.d\n", 10);
// 	test = ft_printf("%.d\n", 10);
// 	printf("test : %d, real : %d\n", test, real);

// 	real = printf("%20.x\n", 0);
// 	test = ft_printf("%20.x\n", 0);
// 	printf("test : %d, real : %d\n", test, real);

// 	return (0);
// }
