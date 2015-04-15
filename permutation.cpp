#include <iostream>
#include <cstring>

using namespace std;

void swap(char *c1, char *c2)
{
	char t = *c1;
	*c1 = *c2;
	*c2 = t;
}

void permute(char *ch, int i, int n)
{
	if(i==n)
	{
		cout<<ch<<endl;
		return;
	}
	int j;
	for(j=i; j<=n; j++)
	{
		swap(ch[i], ch[j]);
		permute(ch, i+1, n);
		swap(ch[i], ch[j]);
	}
}

int main()
{
	char ch[50];
	cin>>ch;
	cout<<endl;
	permute(ch, 0, strlen(ch)-1);
	return 0;
}