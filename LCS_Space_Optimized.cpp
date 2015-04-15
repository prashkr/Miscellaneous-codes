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
    struct node LCS[2][lenb+1];
    int i;
    int j;

    for(i=0; i<=1; i++)
        for(j=0; j<=lenb; j++)
            LCS[i][j].len = 0;

    for(i=1; i<=lena; i++)
    {
        for(j=1; j<=lenb; j++)
        {
            if(a[i-1]==b[j-1])
            {
                LCS[1][j].len = LCS[0][j-1].len + 1;
                LCS[1][j].lcs = LCS[0][j-1].lcs + a[i-1];

            }
                
            else
            {
                LCS[1][j].len = max(LCS[0][j].len, LCS[1][j-1].len);
                if(LCS[1][j].len == LCS[0][j].len)
                {
                    LCS[1][j].lcs = LCS[0][j].lcs;
                }
                else
                {
                    LCS[1][j].lcs = LCS[1][j-1].lcs;
                }
            }
            int x,y;
            // for(x=0; x<=1; x++)
            // {
            //     for(y=0; y<=lenb; y++)
            //     {
            //         cout<<LCS[x][y].len<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;

            for(x=0; x<=lenb; x++)  // copying 2nd row to first row.
            {
                LCS[0][x].len = LCS[1][x].len;
                LCS[0][x].lcs = LCS[1][x].lcs;
            }
        }
    }
    cout<<LCS[1][lenb].len<<endl;
    cout<<LCS[1][lenb].lcs<<endl;
    return 0;
}