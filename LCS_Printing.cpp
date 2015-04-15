#include <bits/stdc++.h>

using namespace std;

#define max(a,b) (a>b)?a:b

struct node 
{
    int len;
    string lcs; // for storing lcs string
};

int main()
{
    string a;
    string b;
    cin>>a>>b;
    int lena = a.length();
    int lenb = b.length();
    struct node LCS[lena+1][lenb+1];
    int i;
    int j;

    // for(i=0; i<=lena; i++)
    //     for(j=0; j<=lenb; j++)
    //         LCS[i][j].len = 0;
    
    for(i=0; i<=lena; i++)
    {
        for(j=0; j<=lenb; j++)
        {
            if(i==0 || j==0)
            {
                LCS[i][j].len=0;
                LCS[i][j].lcs="";
                continue;
            }
            if(a[i-1]==b[j-1])
            {
                LCS[i][j].len = LCS[i-1][j-1].len + 1;
                LCS[i][j].lcs = LCS[i-1][j-1].lcs + a[i-1];

            }
                
            else
            {
                LCS[i][j].len = max(LCS[i-1][j].len, LCS[i][j-1].len);
                if(LCS[i][j].len == LCS[i-1][j].len)
                {
                    LCS[i][j].lcs = LCS[i-1][j].lcs;
                }
                else
                {
                    LCS[i][j].lcs = LCS[i][j-1].lcs;
                }
            }
        }
    }
    cout<<LCS[lena][lenb].len<<endl;
    cout<<LCS[lena][lenb].lcs<<endl;
    return 0;
}