#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;



int main()
{
	char A[100];
	fgets(A, 100, stdin);
	A[strlen(A)-1] = '\0';
	int lenA = strlen(A);

	int i=0; 
	int count=0;
	while(A[i]!='\0')
	{
		if(A[i]==' ')
		{
			count++;
			while(A[i]==' ')
				i++;
		}
		i++;
	}

	if(A[0]==' ')
		count--;
	if(A[lenA-1]==' ')
		count--;

	if(lenA!=0)
		cout<<count+1<<endl;
	else
		cout<<"0"<<endl;


	return 0;
}
