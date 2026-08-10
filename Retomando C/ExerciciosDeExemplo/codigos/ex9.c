#include<stdio.h>

int main(int argc, char const *argv[]){
	char str[] = "IFSP";
	printf("%s\n", str);

	*str = 'X';
	printf("%s\n", str);

	str[1] = 'Y';
	printf("%s\n", str);

	*(str+2) = 'Z';
	printf("%s\n", str);
	//str[1] -> *(str+1)
	//*(str+1) == *(1+str)
	//*(1+str) == 1[str]
	
	3[str] = 'W';
	printf("%s\n", str);
	return 0;
}
/*
 * str - i - 0x10
 * str - f - 0x11
 */

