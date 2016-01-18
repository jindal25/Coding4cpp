#include <stdio.h>

print(char *ptr, char *ptr1)
{
	ptr1[10]='a';
	while (*ptr1 != '\0')
	{
		printf("%c", *ptr1++);
	}

}

main ()
{
	char * ptr = "testthisstring";
	char ptr1[30] = "testthisstring";
	int a = 100; 
	print(ptr,ptr1);
}