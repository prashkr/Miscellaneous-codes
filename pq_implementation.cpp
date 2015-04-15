//Basically a max heap

#include <bits/stdc++.h>

using namespace std;

struct comp
{
    bool operator()(const int &a, const int &b)
    {
        return a<b; // for min heap change to a>b
    }
};

int main()
{
    priority_queue<int, vector<int>, comp> pq;
    pq.push(3);
    pq.push(1);
    pq.push(10);
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;;
        pq.pop();
    }
    return 0;
}