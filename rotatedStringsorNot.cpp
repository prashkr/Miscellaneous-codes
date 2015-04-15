#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void rotated(char *str1, char *str2)
{
	char * str = strcat(str1, str1);
	cout<<str<<endl;
	char *s = strstr(str, str2);
	if(s==NULL)
		printf("False\n");
	else
		printf("True\n");
}

int main()
{
	char str1[] = "ABCD";
	char str2[] = "CDAB";
	rotated(str1, str2);
	return 0;
}