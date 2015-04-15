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
#include <cstring>
using namespace std;

int sieveArray[10000];
bool visited[10000];
int parent[10000];
list<int> *adj;


int stoi(string str)
{
        stringstream id(str);
        int val;
        id >> val;
        //cout<<val<<endl;
        return val;
}

bool isNeighbour(int a, int b)
{
    int error=0;
    if(a%10 != b%10)
        error++;
    a=a/10;
    b=b/10;
    if(a%10 != b%10)
        error++;
    a=a/10;
    b=b/10;
    if(a%10 != b%10)
        error++;
    a=a/10;
    b=b/10;
    if(a%10 != b%10)
        error++;

    if(error==1)
        return true;
    else
        return false;
}

void sieve()
{
    int i=0;
    int j=0;
    for(i=0;i<10000;i++)
    {
        sieveArray[i]=i;
    }
    for(i=2;i<10000;i++)
    {
        if(sieveArray[i]==0)
            continue;
        for(j=2*i ; j<10000; j=j+i)
        {
            if(sieveArray[j]%i==0)
                sieveArray[j]=0;
        }
    }

}
int bfs(string a, string b)
{
    //cout<<"BFS"<<endl;
    //int initial = stoi(a);
    int final = stoi(b);

    int path = 0;
    int i=0;
    int size=0;
    bool found = false;
    memset(visited, false, 10000);
    for(i=0;i<10000;i++)
        parent[i]=-1;
    queue<int> Q;
    Q.push(stoi(a));
    visited[stoi(a)]=true;
    int j=0;
    list<int>::iterator it;
    while(!Q.empty())
    {
        //cout<<"Q not empty"<<endl;
        int temp = Q.front();
        //string temp = a;
        //cout<<Q.size()<<endl;
        Q.pop();
        //cout<<temp<<endl;
        for(it=adj[temp].begin();it!=adj[temp].end();it++)
        {
            if(sieveArray[*it]!=0 && visited[*it]==false)
            {
                //cout<<"a"<<endl;
                visited[*it]=true;
                parent[*it]=temp;
                if((*it)==stoi(b))
                {
                    found=true;
                    break;
                }
                //cout<<"b"<<endl;
                Q.push(*it);
            }
        }
    }

        if(found==false)
                return -1;
        else
        {
            while(parent[final]!=-1)
            {
                path++;
                final = parent[final];
            }
            return path;
        }

}

int main() {

    sieve();
    int i=0;
    int j=0;
    int size=0;
    for(i=1000;i<10000;i++)
    {
        if(sieveArray[i]!=0)
            size++;
    }
    int primes[size];
    for(i=1000;i<10000;i++)
    {
        if(sieveArray[i]!=0)
        {
            primes[j]=sieveArray[i];
            j++;
        }
    }
    /*for(i=0;i<size;i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<endl;*/
    adj = new list<int>[10000];
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(isNeighbour(primes[i], primes[j]))
            {
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }

    int t;
    scanf("%d",&t);
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(a==b)
        {
            printf("0\n");
            continue;
        }
        int path;
        path = bfs(a, b);
        if(path == -1)
            printf("Impossible\n");
        else
            printf("%d\n",path);
        memset(visited, false, 10000);
    }
    return 0;
}
