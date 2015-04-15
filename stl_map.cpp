//Sorting A1 according to the order in A2 using map

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int m = sizeof(A1)/sizeof(A1[0]);
    int n = sizeof(A2)/sizeof(A2[0]);
    sort(A1, A1+m);
    map<int, int> M;
    int i=0;
    for(i=0; i<m; i++)
    {
    	M[A1[i]]++;
    }

    map<int, int>::iterator it;
    for(i=0; i<n; i++)
    {
    	it=M.find(A2[i]);
    	if(it!=M.end())
    	{
    		int count = it->second;
    		int j;
    		for(j=0; j<count; j++)
    		{
    			cout<<A2[i]<<" ";
    		}
    		M.erase(it);
    	}
    }

    for(i=0; i<m; i++)
    {

    	it = M.find(A1[i]);
    	if(it!=M.end())
    	{
    		int count = it->second;
    		int j;
    		for(j=0; j<count; j++)
    			cout<<A1[i]<<" ";
    	}
    }
    cout<<endl;

	return 0;
}