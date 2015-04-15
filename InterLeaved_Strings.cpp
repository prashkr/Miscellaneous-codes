#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void interleave(char *A, char *B, char *data, int i, int idx1, int idx2, int lenA, int lenB)
{
	if(idx1==lenA+1 &&  idx2==lenB+1)
	{
		//data[lenA+lenB-1]='\0';
		cout<<data<<endl;
		return;
	}

	if(idx1<=lenA)
	{
		data[i] = A[idx1];
		interleave(A, B, data, i+1, idx1+1, idx2, lenA, lenB);
	}

	if(idx2<=lenB)
	{
		data[i] = B[idx2];
		interleave(A, B, data, i+1, idx1, idx2+1, lenA, lenB);
	}
}

int main()
{
	char A[100];
	char B[100];
	fgets(A, 100, stdin);
	fgets(B, 100, stdin);
	A[strlen(A)-1] = '\0';
	B[strlen(B)-1] = '\0';
	int lenA = strlen(A);
	int lenB = strlen(B);
	char *data = (char *)malloc(sizeof(lenA+lenB));
	data[lenA+lenB-1]='\0';
	interleave(A, B, data, 0, 0, 0, lenA-1, lenB-1);
	return 0;
}