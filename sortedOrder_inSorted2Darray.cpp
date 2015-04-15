#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define N 4

struct comp
{
    bool operator()(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2 )
    {
        return p1.first > p2.first;
    }
};

void printsorted(int mat[][N])
{
    priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, comp> pq;
    int i, j;
    for(i=0; i<N; i++)
    {
        pq.push(MP(mat[0][i], MP(0, i)));
    }
    pair<int, pair<int, int> > p;
    while(!pq.empty())
    {
        p = pq.top();
        pq.pop();
        int i, j;
        i=p.second.first;
        j=p.second.second;
        cout<<p.first<<" ";
        if(i+1<N)
            pq.push(MP(mat[i+1][j], MP(i+1, j)));
    }
}

int main()
{
    int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
    printsorted(mat);
    return 0;
}