#include "main.h"

/**
 * printf_HEX_aux - prints an hexgecimal number.
 * @num: number to print.
 * Return: counter.
 */
int printf_HEX_aux(unsigned int num)
{
	int i;
	int *list;
	int sum = 0;
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
			list[i] = list[i] + 7;
		_putchar(list[i] + '0');
	}
	free(list);
	return (sum);
}
