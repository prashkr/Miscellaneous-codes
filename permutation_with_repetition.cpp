#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

void permutationWithRep(char *str, char *data, int index, int len, int k)
{
	int i;
	for(i=0; i<=len; i++)
	{
		data[index] = str[i];

		if(index==k)
			cout<<data<<endl;
		else
			permutationWithRep(str, data, index+1, len, k);
	}
}

bool compare(char a, char b)
{
	return (a<b);
}

int main()
{
	char str[100];
	fgets(str, 100, stdin);
	str[strlen(str)-1] = '\0';
	sort(str, str+strlen(str), compare);
	char *data = (char *)malloc(sizeof(100));
	// int k;  // k combination	
	// cin>>k;
	int len = strlen(str)-1;

	permutationWithRep(str, data, 0, len, k-1);

	return 0;
}