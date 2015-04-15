#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int visited[5][5]={0};
void islands(int M[][5],int i, int j)
{
    if(M[i][j]==0||visited[i][j])
        return;
    else if(i<0||j<0||i>4||j>4)
    {
        return;
    }
    else
    {
        visited[i][j]=1;
        islands(M,i,j+1);
        islands(M,i,j-1);
        islands(M,i-1,j);
        islands(M,i+1,j);
        islands(M,i+1,j+1);
        islands(M,i-1,j+1);
        islands(M,i-1,j-1);
        islands(M,i+1,j-1);
    }
}

int main()
{
    int M[5][5]= {  {1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1} };
    int i=0;
    int j=0;
    int count=0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(!visited[i][j] && M[i][j]==1)
            {
                count++;
                islands(M,i,j);       
            }
        }
    }
    cout<<count;
    return 0;
}
