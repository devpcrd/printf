#include "main.h"

/**
 * printf_HEX - prints an hexadecimal number.
 * @arg: arguments.
 * Return: sum.
 */
int printf_HEX(va_list val)
{
	int i;
	int *list;
	int sum = 0;
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		sum++;
	}
	sum++;
	list = malloc(sum * sizeof(int));

	for (i = 0; i < sum; i++)
	{
		list[i] = temp % 16;
		temp /= 16;
	}
	for (i = sum - 1; i >= 0; i--)
	{
		if (list[i] > 9)
			array[i] = list[i] + 7;
		_putchar(list[i] + '0');
	}
	free(list);
	return (sum);
}
