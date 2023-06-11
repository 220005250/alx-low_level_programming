#include <stdio.h>
#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 * Return: Pointer to the result string
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0, sum = 0, i = 0;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);
	len1--;
	len2--;
	for (; len1 >= 0 || len2 >= 0; len1--, len2--, i++)
	{
		sum = carry;
		if (len1 >= 0)
			sum += (n1[len1] - '0');
		if (len2 >= 0)
			sum += (n2[len2] - '0');
		carry = sum / 10;
		sum %= 10;
		r[i] = (sum + '0');
	}
	if (carry)
	{
		r[i] = (carry + '0');
		i++;
	}
	r[i] = '\0';
	if (i > size_r)
		return (0);
	return (r);
}
