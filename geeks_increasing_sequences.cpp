/*
Print all increasing sequences of length k from first n natural numbers
*/

#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back

void print(int n, int k, int idx, int val, int temp[])
{
    if(idx>=k)
    {
        int i;
        for(i=0; i<k; i++)
            cout<<temp[i]<<" ";
        cout<<endl;
        return;
    }
    else
    {
        int i;
        for(i=val; i<=n-k+1+idx; i++)
        {
            temp[idx] = i;
            print(n, k, idx+1, i+1, temp);
        }
    }
}

int main()
{
   
    int n, k;
    cin>>n>>k;
    int temp[k];
    print(n, k, 0, 1, temp);

    return 0;
}
