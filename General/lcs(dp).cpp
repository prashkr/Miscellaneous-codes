#include<iostream>

#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int main()
{
    string a = "ABCBDAB";
    string b = "BDCABC";

    int n = a.length();
    int m = b.length();

    int lcs[n+1][m+1];
    int i=0;
    for(i=0;i<=n;i++)
        lcs[i][0]=0;
    for(i=0;i<=m;i++)
        lcs[0][i]=0;

    int j=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                lcs[i][j]=lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }

    }
    cout<< lcs[n][m]<<endl;


}
