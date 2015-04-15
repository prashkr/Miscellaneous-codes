#include<iostream>
#include<algorithm>
using namespace std;
int cnt=0;
void swap(char *a, char *b)
{
    char temp = *a;
    *a=*b;
    *b=temp;
}

void permutations(string a, int i, int n)
{
    if(i==n)
    {
        cout<<a<<endl;
        cnt=cnt+1;;
    }

    else
    {
        int j=0;
        for(j=i;j<n;j++)
        {
            swap(a[i],a[j]);
            permutations(a,i+1,n);
            swap(a[i],a[j]);
        }
    }
}

int main()
{
    string a = "abcd";
    permutations(a,0,a.length());
    cout << cnt<<endl;
    return 0;
}
