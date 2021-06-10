
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char c = 'a';
	int res;

/* 	res = ft_printf("[%c %c %*c]\n", c, 0, -10, c);
	printf("ft_printf res is: %d\n", res);

	res = printf("[%c %c %*c]\n", c, 0, -10, c);
	printf("printf res is: %d\n", res);

	res = ft_printf("[%c]\n", '\0');
	printf("ft_printf res is: %d\n", res);

	res = printf("[%c]\n", '\0');
	printf("printf res is: %d\n", res);
 */
/* 	res = ft_printf("[%5c]\n", '\0');
	printf("ft_printf res is: %d\n", res);

	res = printf("[%5c]\n", '\0');
	printf("printf res is: %d\n", res);
 */

//	res = ft_printf("[%-6c]\n", 0);
//	printf("ft_printf res is: %d\n", res);

//	res = printf("[%-6c]\n", 0);
//	printf("printf res is: %d\n", res);
/* 
	res = ft_printf("[%-5c]\n", '\0');
	printf("ft_printf res is: %d\n", res);

	res = printf("[%-5c]\n", '\0');
	printf("printf res is: %d\n", res); */

	char n = '\0';
	//char *str = (char *)malloc(1);
	//str[0] = n;
	
	
	res = printf("[%-22c]\n", '1');
	printf("printf res is: %d\n", res);

	res = ft_printf("[%-22c]\n", '1');
	printf("ft_printf res is: %d\n", res);

	//printf("test print null char inside a string\n%s\n", str);

	return (0);
}