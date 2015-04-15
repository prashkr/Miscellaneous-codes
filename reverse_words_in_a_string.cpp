#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void reverseString(char *ch, int start, int end)
{
	while(start<end)
	{
		char temp = ch[start];
		ch[start] = ch[end];
		ch[end] = temp;
		start++;
		end--;
	}
}

void reverseWords(char *ch)
{
	int i=0;
	int start_index=0;
	while(ch[i]!='\n')
	{
		if(ch[i]==' ')
		{
			reverseString(ch, start_index, i-1);
			while(ch[i]==' ')
				i++;
			start_index = i;
		}
		i++;
	}
	reverseString(ch, start_index, i-1);
}

int main()
{
	char ch[50];
	fgets(ch, 50, stdin); // Important. If you do scanf %s then after a whitespace the string is not read
	reverseWords(ch);
	reverseString(ch, 0, strlen(ch)-1);
	cout<<ch<<endl;
	return 0;
}